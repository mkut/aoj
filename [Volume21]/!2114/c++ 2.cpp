#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
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

inline bool draw(Map& _map, bool* result, int y, int x, bool white)
{
	if(result[y*8+x] == white)
	{
		if(++_map._data[y][x] >= 5) return true;
	}
	return false;
}

class Solver
{
  private:
	stack<Map> st;
	bool* result;
	int H;
	int W;
	int x;
	int y;
	int _max;
	int _min;
	int count;
	
  public:
	Solver(bool* result, int H, int W)
	{
		this->st.push(Map());
		this->result = result;
		this->H = H;
		this->W = W;
	}
	int solve_max()
	{
		count = 0;
		_max = -100;
		pointerres();
		solve_max(0, false);
		solve_max(0, true);
		return _max;
	}
	int solve_min()
	{
		count = 0;
		_min = 100;
		pointerres();
		solve_min(0, true);
		solve_min(0, false);
		return _min;
	}
	
  private:
	void solve_max(int whitenum, bool white)
	{
		//if(++count >= 10000000) return;
		if(y == H){ _max = H*W - whitenum; return; }
		if(whitenum >= H*W - _max){ return; }
		
		Map next(&st.top());
		
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++)
				if(draw(next, result, _p(y+i, H), _p(x+j, W), white))
					return;
		
		st.push(next);
		pointerinc();
		solve_max(whitenum + (white ? 1 : 0), false);
		solve_max(whitenum + (white ? 1 : 0), true);
		pointerdec();
		st.pop();
	}
	void solve_min(int blacknum, bool white)
	{
		//if(++count >= 1000000) return;
		if(y == H){ _min = blacknum; return; }
		if(blacknum >= _min){ return; }
		
		Map next(&st.top());
		
		for(int i = -1; i <= 1; i++)
			for(int j = -1; j <= 1; j++)
				if(draw(next, result, _p(y+i, H), _p(x+j, W), white))
					return;
		
		st.push(next);
		pointerinc();
		solve_min(blacknum + (white ? 0 : 1), true);
		solve_min(blacknum + (white ? 0 : 1), false);
		pointerdec();
		st.pop();
	}
	
	void pointerinc()
	{
		if(++x == W)
		{
			x = 0;
			y++;
		}
	}
	void pointerdec()
	{
		if(x-- == 0)
		{
			x = W-1;
			y--;
		}
	}
	void pointerres()
	{
		x = 0;
		y = 0;
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