#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

inline int _p(int val, int lim)
{
	return val < 0 ? 0 : (val >= lim ? lim-1 : val);
}

inline void draw(int* map, bool* result, int y, int x, bool white)
{
	if(result[y*8+x] == white)
	{
		map[y*8+x]++;
	}
}

pair<int,int> solve(int* _map, bool* result, int H, int W, int y, int x)
{
	if(y == H) return pair<int,int>(0,0);
	
	pair<int,int> ret = pair<int,int>(-100,100);
	int map_white[8][8], map_black[8][8];
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			map_white[i][j] = _map[i*8+j];
			map_black[i][j] = _map[i*8+j];
		}
	}
	
	bool white_ok = true;
	bool black_ok = true;
	
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			draw(map_white[0], result, _p(y+i, H), _p(x+j, W), true);
			draw(map_black[0], result, _p(y+i, H), _p(x+j, W), false);
		}
	}
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(map_white[_p(y+i, H)][_p(x+j, W)] >= 5)
			{
				white_ok = false;
			}
			if(map_black[_p(y+i, H)][_p(x+j, W)] >= 5)
			{
				black_ok = false;
			}
		}
	}
	if(white_ok)
	{
		pair<int,int> next = solve(map_white[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret.first = max(ret.first, next.first);
		ret.second = min(ret.second, next.second);
	}
	if(black_ok)
	{
		pair<int,int> next = solve(map_black[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret.first = max(ret.first, next.first+1);
		ret.second = min(ret.second, next.second+1);
	}
	
	return ret;
}

int main()
{
	int W, H;
	int n = 0;
	while(cin >> W >> H, W != 0 || H != 0)
	{
		n++;
		bool result[8][8];
		for(int i = 0; i < H; i++)
		{
			string input;
			cin >> input;
			for(int j = 0; j < W; j++)
			{
				result[i][j] = input[j] == '#';
			}
		}
		
		int _map[8][8] = {};
		pair<int,int> ans = solve(_map[0], result[0], H, W, 0, 0);
		int _max = ans.first;
		int _min = ans.second;
		if(_max - _min >= 0)
		{
			printf("Case %d: %d\n", n, _max - _min);
		}
		else
		{
			printf("Case %d: Impossible\n", n);
		}
	}
	return 0;
}