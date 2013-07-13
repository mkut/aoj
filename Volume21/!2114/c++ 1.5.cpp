#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

inline int _p(int val, int lim)
{
	return val < 0 ? 0 : (val >= lim ? lim-1 : val);
}

bool instant_max(int* map_black, bool* result, int H, int W, int y, int x)
{
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(!result[_p(y+i, H)*8+_p(x+j, W)] && map_black[_p(y+i, H)*8+_p(x+j, W)] + 4 + i*3 + j >= 5) return false;
		}
	}
	return true;
}
bool instant_min(bool* result, int H, int W, int y, int x)
{
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(result[_p(y+i, H)*8+_p(x+j, W)]) return false;
		}
	}
	return true;
}

inline void draw(int* map, bool* result, int y, int x, bool white)
{
	if(result[y*8+x] == white)
	{
		map[y*8+x]++;
	}
}

int solve_max(int* _map, bool* result, int H, int W, int y, int x)
{
	if(y == H) return 0;
	
	int ret = -100;
	int map_white[8][8], map_black[8][8];
	
	for(int i = 0; i < H; i++)
	{
		for(int j = 0; j < W; j++)
		{
			map_white[i][j] = _map[i*8+j];
			map_black[i][j] = _map[i*8+j];
		}
	}
	
	if(instant_max(map_black[0], result,  H, W, y, x))
	{
		return solve_max(map_black[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1) +1;
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
	for(int i = -1; i <= 0; i++)
	{
		for(int j = -1; j <= 0; j++)
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
		int next = solve_max(map_white[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret = max(ret, next);
	}
	if(black_ok)
	{
		int next = solve_max(map_black[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret  = max(ret, next + 1);
	}
	
	return ret;
}


int solve_min(int* _map, bool* result, int H, int W, int y, int x)
{
	if(y == H) return 0;
	
	if(instant_min(result, H, W, y, x))
	{
		return solve_min(_map, result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
	}
	
	int ret = 100;
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
	for(int i = -1; i <= 0; i++)
	{
		for(int j = -1; j <= 0; j++)
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
		int next = solve_min(map_white[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret = min(ret, next);
	}
	if(black_ok)
	{
		int next = solve_min(map_black[0], result, H, W, x+1 == W ? y+1 : y, x+1 == W ? 0 : x+1);
		ret  = min(ret, next + 1);
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
		int _max = solve_max(_map[0], result[0], H, W, 0, 0);
		int _min = solve_min(_map[0], result[0], H, W, 0, 0);
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