#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

struct state
{
	int tx, ty, kx, ky;
	state(int TX, int TY, int KX, int KY) : tx(TX), ty(TY), kx(KX), ky(KY) {}
};

bool done[52][52][52][52];

int main()
{
	int X, Y;
	while(cin >> X >> Y, X)
	{
		int tx, ty, kx, ky;
		cin >> tx >> ty >> kx >> ky;
		vector<vector<int> > flr(Y+2, vector<int>(X+2,1));
		for(int i = 1; i <= Y; i++)
			for(int j = 1; j <= X; j++)
				cin >> flr[i][j];
		memset(done, 0, sizeof(done));
		done[tx][ty][kx][ky] = true;
		vector<state> prev(1, state(tx, ty, kx, ky));
		int ans = -1;
		
		for(int count = 0; prev.size() && count < 100 && ans == -1; count++)
		{
			vector<state> next;
			for(vector<state>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				//cout << it->tx << "," << it->ty << "|" << it->kx << "," << it->ky << endl;
				if(it->tx == it->kx && it->ty == it->ky)
				{
					ans = count;
					break;
				}
				for(int i = 0; i < 4; i++)
				{
					int ntx = it->tx + dx[i];
					int nty = it->ty + dy[i];
					if(flr[nty][ntx]) ntx -= dx[i], nty -= dy[i];
					int nkx = it->kx - dx[i];
					int nky = it->ky - dy[i];
					if(flr[nky][nkx]) nkx += dx[i], nky += dy[i];
					if(!done[ntx][nty][nkx][nky])
					{
						next.push_back(state(ntx, nty, nkx, nky));
						done[ntx][nty][nkx][nky] = true;
					}
				}
			}
			prev = next;
		}
		if(ans == -1)
			cout << "NA" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
