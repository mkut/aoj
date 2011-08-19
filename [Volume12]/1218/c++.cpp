#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct state
{
	int x, y, bx, by, step;
	state(int X, int Y, int bX, int bY, int Step) : x(X), y(Y), bx(bX), by(bY), step(Step) {}
	
	bool operator<(const state& a) const
	{
		return step > a.step;
	}
};

int main()
{
	int w, h;
	while(cin >> w >> h, w)
	{
		vector<vector<int> > _map(h+2, vector<int>(w+2, 1));
		int sx, sy, bx, by, gx, gy;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
			{
				cin >> _map[i][j];
				if(_map[i][j] == 2)
					bx = i, by = j, _map[i][j] = 0;
				else if(_map[i][j] == 3)
					gx = i, gy = j, _map[i][j] = 0;
				else if(_map[i][j] == 4)
					sx = i, sy = j, _map[i][j] = 0;
			}
		
		bool used[9][9][9][9] = {};
		used[sx][sy][bx][by] = true;
		priority_queue<state> Q;
		Q.push(state(sx, sy, bx, by, 0));
		int ans = -1;
		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			int X = cur.x, Y = cur.y, bX = cur.bx, bY = cur.by, step = cur.step;
			used[X][Y][bX][bY] = true;
			
			//cout << X << "," << Y << "," << bX << "," << bY << "," << step << endl;
			if(bX == gx && bY == gy)
			{
				ans = step;
				break;
			}
			
			const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
			for(int k = 0; k < 4; k++)
			{
				int nextX = X + dx[k], nextY = Y + dy[k];
				if(nextX == bX && nextY == bY)
				{
					int nextBX = nextX + dx[k], nextBY = nextY + dy[k];
					if(_map[nextBX][nextBY] == 0 && !used[nextX][nextY][nextBX][nextBY])
						Q.push(state(nextX, nextY, nextBX, nextBY, step+1));
				}
				else if(_map[nextX][nextY] == 0 && !used[nextX][nextY][bX][bY])
					Q.push(state(nextX, nextY, bX, bY, step));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
