#include <iostream>
#include <vector>
using namespace std;

class solver
{
  private:
	vector<string> _map;
	
  public:
	solver(vector<string> _map)
	{
		this->_map = _map;
	}
	
	int solve()
	{
		int r = 0;
		while(!draw(0,0))
		{
			r++;
			clear();
		}
		return r;
	}
	
	bool clear()
	{
		for(int i = 0; i < _map.size(); i++)
		{
			for(int j = 0; j < _map[i].length(); j++)
			{
				if(_map[i][j] == ' ') _map[i][j] = '.';
			}
		}
	}
	
	bool draw(int x, int y)
	{
		if(x < 0 || x >= _map.size() || y < 0 || y >= _map[0].length()) return false;
		
		if(_map[x][y] == '.')
		{
			_map[x][y] = ' ';
			if(draw(x-1, y)) return true;
			if(draw(x+1, y)) return true;
			if(draw(x, y-1)) return true;
			if(draw(x, y+1)) return true;
		}
		else if(_map[x][y] == '#')
		{
			_map[x][y] = ' ';
			draw2(x-1, y);
			draw2(x+1, y);
			draw2(x, y-1);
			draw2(x, y+1);
		}
		else if(_map[x][y] == '&')
		{
			return true;
		}
		return false;
	}
	void draw2(int x, int y)
	{
		if(_map[x][y] == '#')
		{
			_map[x][y] = ' ';
			draw2(x-1, y);
			draw2(x+1, y);
			draw2(x, y-1);
			draw2(x, y+1);
		}
	}
};

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<string> _map;
		string edge = "";
		for(int i = 0; i < n+2; i++) edge += '.';
		_map.push_back(edge);
		for(int i = 0; i < m; i++)
		{
			string tmp; cin >> tmp;
			_map.push_back('.'+tmp+'.');
		}
		_map.push_back(edge);
		
		solver prob(_map);
		cout << prob.solve() << endl;
	}
	return 0;
}