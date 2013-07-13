#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
  private:
	vector<string> _map;
	int H;
	int W;
	int _max;
	
  public:
	solver(int H, int W, vector<string> _map)
	{
		this->H = H;
		this->W = W;
		this->_map = _map;
	}
	
	int solve()
	{
		_max = 0;
		return _solve(0, 0, H, W);
	}
	
  private:
	int _solve(int top, int left, int bottom, int right)
	{
		if((bottom - top) * (right - left) <= _max) return 0;
		
		int ret = 0;
		for(int i = (top+bottom)/2; i != bottom; i = top+bottom-i-(i >= (top+bottom+1)/2 ? 1 : 0))
		{
			if(i == bottom) break;
			for(int j = (left+right)/2; j != right; j = left+right-j-(j >= (left+right+1)/2 ? 1 : 0))
			{
				if(_map[i][j] == '*')
				{
					ret = max(ret, _solve(i+1, left, bottom, right));
					ret = max(ret, _solve(top, left, i, right));
					ret = max(ret, _solve(top, left, bottom, j));
					ret = max(ret, _solve(top, j+1, bottom, right));
					_max = max(ret, _max);
					return ret;
				}
			}
		}
		
		return (bottom - top) * (right - left);
	}
};

int main()
{
	int H, W;
	while(cin >> H >> W, H != 0)
	{
		vector<string> _map;
		for(int i = 0; i < H; i++)
		{
			string tmp;
			cin >> tmp;
			_map.push_back(tmp);
		}
		solver prob(H, W, _map);
		cout << prob.solve() << endl;
	}
	
	return 0;
}