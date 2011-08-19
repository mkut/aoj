//randomized algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct Map
{
  public:
	int _data[8][8];
	
	Map()
	{
		for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		_data[i][j] = 0;
	}
	Map(Map* _map)
	{
		for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
		_data[i][j] = _map->_data[i][j];
	}
};

inline int _p(int val, int lim)
{
	return val < 0 ? 0 : (val >= lim ? lim-1 : val);
}

inline bool _draw(Map& _map, bool* result, int y, int x, bool white)
{
	if(result[y*8+x] == white)
	{
		if(++_map._data[y][x] >= 5) return true;
	}
	return false;
}
inline bool draw(Map& _map, bool* result, int H, int W, int y, int x, bool white)
{
	for(int i = -1; i <= 1; i++)
	{
		for(int j = -1; j <= 1; j++)
		{
			if(_draw(_map, result, _p(y+i, H), _p(x+j, W), white))
			{
				return true;
			}
		}
	}
	return false;
}

class Solver
{
  private:
	bool* result;
	int H;
	int W;
	
  public:
	Solver(bool* result, int H, int W)
	{
		this->result = result;
		this->H = H;
		this->W = W;
	}
	int solve(bool _max)
	{
		int ret = _max ? -100 : 100;
		for(int i = 0; i < 100000; i++)
		{
			vector<pair<int,int> > remain;
			int count = 0;
			for(int i = 0; i < H; i++)
			{
				for(int j = 0; j < W; j++)
				{
					remain.push_back(pair<int,int>(i,j));
				}
			}
			random_shuffle(remain.begin(), remain.end());
			Map st;
			for(vector<pair<int, int> >::iterator it = remain.begin(); it != remain.end(); it++)
			{
				Map tmp(st);
				if(draw(tmp, result, H, W, it->first, it->second, !_max))
				{
					if(draw(st, result, H, W, it->first, it->second, _max))
					{
						count = _max ? -100 : 100;
						break;
					}
					else
					{
						if(!_max) count++;
					}
				}
				else
				{
					draw(st, result, H, W, it->first, it->second, !_max);
					if(_max) count++;
				}
			}
			
			if(_max) ret = max(ret, count);
			else ret = min(ret, count);
		}
		
		return ret;
	}
	int solve_max()
	{
		return solve(true);
	}
	int solve_min()
	{
		return solve(false);
	}
};

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
		
		Map _map;
		Solver solver(result[0], H, W);
		int _max = solver.solve_max();
		int _min = solver.solve_min();
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