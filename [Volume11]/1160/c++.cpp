#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void draw(vector<vector<int> >& _map, int x, int y)
{
	if(_map[x][y] == 0)
		return;
	_map[x][y] = 0;
	const int dx[] = {-1,-1,-1,0,0,0,1,1,1}, dy[] = {-1,0,1,-1,0,1,-1,0,1};
	for(int i = 0; i < 9; i++)
		draw(_map, x+dx[i], y+dy[i]);
}

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		vector<vector<int> >_map(h+2);
		_map[0] = vector<int>(w+2);
		_map[h+1] = vector<int>(w+2);
		for(int i = 1; i <= h; i++)
		{
			_map[i] = vector<int>(w+2);
			for(int j = 1; j <= w; j++)
				cin >> _map[i][j];
		}
		
		int count = 0;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
				if(_map[i][j] == 1)
				{
					draw(_map, i, j);
					count++;
				}
		cout << count << endl;
	}
	return 0;
}
