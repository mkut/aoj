#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <set>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
	int W, H, N;
	while(cin >> W >> H >> N, W)
	{
		vector<string> view(H*2+1, string(W*2+1, '.'));
		for(int i = 0; i <= 2*H; i++)
			view[i][0] = view[i][W*2] = '#';
		for(int i = 0; i <= 2*W; i++)
			view[0][i] = view[H*2][i] = '#';
		for(int i = 0; i < N; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 == x2)
			{
				for(int j = min(y1, y2)*2; j <= max(y1, y2)*2; j++)
					view[j][x1*2] = '#';
			}
			else
			{
				for(int j = min(x1, x2)*2; j <= max(x1, x2)*2; j++)
					view[y1*2][j] = '#';
			}
		}
		int ex1, ey1, ex2, ey2, gx, gy, sx, sy, dir;
		cin >> ex1 >> ey1 >> ex2 >> ey2 >> gx >> gy;
		sx = ex1 == ex2 ? (ex1 == 0 ? 1 : W*2-1) : ex1 + ex2;
		sy = ey1 == ey2 ? (ey1 == 0 ? 1 : H*2-1) : ey1 + ey2;
		gx = gx * 2 + 1;
		gy = gy * 2 + 1;
		dir = ey1 == ey2 ? (ey1 == 0 ? 0 : 2) : (ex1 == 0 ? 1 : 3);
		int ans = 1;
		set<int> done;
		for(int X = sx, Y = sy; X != gx || Y != gy; ans++)
		{
			int state = X + (Y<<10) + (dir<<20);
			if(done.count(state))
			{
				ans = -1;
				break;
			}
			done.insert(state);
			bool ok = false;
			for(int i = 3; i < 7; i++)
			{
				int nd = (dir+i)%4;
				int nx = X + dx[nd], ny = Y + dy[nd];
				if(view[ny][nx] != '#')
				{
					dir = nd;
					X += dx[nd] * 2;
					Y += dy[nd] * 2;
					ok = true;
					break;
				}
			}
			if(!ok)
			{
				ans = -1;
				break;
			}
		}
		if(ans == -1)
			cout << "Impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
