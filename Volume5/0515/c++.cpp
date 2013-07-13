#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b;
	while(cin >> a >> b, a != 0)
	{
		vector<vector<int> > _map(a+2);
		for(int i = 0; i < a+2; i++) _map[i] = vector<int>(b+2);
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			_map[x][y] = -1;
		}
		_map[0][1] = 1;
		
		for(int i = 1; i <= a; i++)
		{
			for(int j = 1; j <= b; j++)
			{
				if(_map[i][j] == -1) _map[i][j] = 0;
				else _map[i][j] = _map[i-1][j] + _map[i][j-1];
			}
		}
		cout << _map[a][b] << endl;
	}
	return 0;
}