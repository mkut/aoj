#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct state
{
	int x, y, hp;
	state(int X, int Y, int HP) : x(X), y(Y), hp(HP) {}
};

int main()
{
	int w, h;
	while(cin >> w >> h, w)
	{
		vector<vector<int> > _map(h, vector<int>(w));
		int sx, sy, gx, gy;
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				cin >> _map[i][j];
				if(_map[i][j] == 2)
					sx = i, sy = j, _map[i][j] = 1;
				if(_map[i][j] == 3)
					gx = i, gy = j, _map[i][j] = 1;
			}
		
		vector<state> prev(1, state(sx, sy, 6));
		vector<vector<int> > memo(h, vector<int>(w));
		memo[sx][sy] = 6;
		bool ok = false;
		for(int time = 0; prev.size(); time++)
		{
			vector<state> next;
			for(vector<state>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				int x = it->x, y = it->y, hp = it->hp;
				//cout << x << "," << y << "," << hp << endl;
				if(x == gx && y == gy && hp > 0)
				{
					cout << time << endl;
					ok = true;
					break;
				}
				const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
				for(int i = 0; i < 4; i++)
				{
					int X = x+dx[i], Y = y+dy[i], HP = hp-1;
					if(X < 0 || X >= h || Y < 0 || Y >= w) continue;
					if(_map[X][Y] != 0 && HP > memo[X][Y])
					{
						if(_map[X][Y] == 4) HP = 6;
						memo[X][Y] = HP;
						next.push_back(state(X, Y, HP));
					}
				}
			}
			if(ok) break;
			prev = next;
		}
		if(!ok) cout << -1 << endl;
	}
	return 0;
}
