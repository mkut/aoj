#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>

int main()
{
	int t, n;
	while(cin >> t >> n, t)
	{
		vector<vector<int> > mapinfo(200, vector<int>(200));
		for(int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			x += 100; y += 100;
			mapinfo[x][y] = -1;
		}
		int sx, sy; cin >> sx >> sy;
		sx += 100; sy += 100;
		mapinfo[sx][sy] = 1;
		for(int i = 0; i < t; i++)
		{
			vector<vector<int> > nextmapinfo = mapinfo;
			const int dx[] = {0,1,-1,1,-1,0}, dy[] = {1,1,0,0,-1,-1};
			for(int x = 10; x < 190; x++)
				for(int y = 10; y < 190; y++)
				{
					if(mapinfo[x][y] != 0)
						continue;
					for(int k = 0; k < 6; k++)
					{
						int X = x + dx[k], Y = y + dy[k];
						if(mapinfo[X][Y] == 1)
						{
							nextmapinfo[x][y] = 1;
							break;
						}
					}
				}
			mapinfo = nextmapinfo;
		}

		int ans = 0;
		for(int x = 0; x < 200; x++)
			for(int y = 0; y < 200; y++)
				ans += mapinfo[x][y] == 1 ? 1 : 0;

		cout << ans << endl;
	}
	return 0;
}
