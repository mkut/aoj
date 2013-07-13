#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class solver
{
	map<pair<int,int>, int> memo;
	vector<vector<int> > _map;
	
public:
	solver(vector<vector<int> > _Map)
	{
		_map = _Map;
	}
	int solve(int i, int j)
	{
		if(memo.count(pair<int,int>(i,j)) > 0)
			return memo[pair<int,int>(i,j)];
		
		int res = 0;
		if(_map[i][j] == 1)
		{
			res = 0;
		}
		else if(_map[i][j] == 3 || i >= _map.size() - 3)
		{
			res = 1;
		}
		else if(_map[i][j] == 0)
		{
			res = solve(i+1, j);
			if(_map[i+1][j-1] == 0)
				res += solve(i+1, j-1);
			if(_map[i+1][j+1] == 0)
				res += solve(i+1, j+1);
		}
		else if(_map[i][j] == 2)
		{
			res = solve(i+2, j);
		}
		memo[pair<int,int>(i,j)] = res;
		return res;
	}
};

int main()
{
	int X, Y;
	while(cin >> X >> Y, X != 0)
	{
		vector<vector<int> > _map(Y+2);
		for(int i = 0; i < Y+2; i++)
		{
			_map[i] = vector<int>(X+2);
			for(int j = 0; j < X+2; j++)
			{
				if(i >= Y)
					_map[i][j] = 3;
				else if(j == 0 || j == X+1)
					_map[i][j] = 1;
				else
					cin >> _map[i][j];
			}
		}
		
		solver prob(_map);
		
		int ans = 0;
		for(int i = 1; i <= X; i++)
			ans += prob.solve(0, i);
		
		cout << ans << endl;
	}
	return 0;
}
