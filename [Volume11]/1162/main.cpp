#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <queue>
#include <cstdlib>

struct road
{
	int to, d, lim;
	road(int to, int d, int lim) : to(to), d(d), lim(lim) {}
};

struct state
{
	int pos, from, speed;
	double time;
	state(int pos, int from, int speed, double time)
		: pos(pos), from(from), speed(speed), time(time) {}
	bool operator<(const state& a) const { return time > a.time; }
};

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		int s, g; cin >> s >> g; s--; g--;
		vector<vector<road> > roads(n);
		for(int i = 0; i < m; i++)
		{
			int x, y, d, c; cin >> x >> y >> d >> c; x--; y--;
			roads[x].push_back(road(y, d, c));
			roads[y].push_back(road(x, d, c));
		}

		priority_queue<state> Q;
		Q.push(state(s, s, 0, 0.0));
		double ans = -1;
		bool done[32][32][32] = {};

		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			int pos = cur.pos, speed = cur.speed, from = cur.from;
			double time = cur.time;
			//cout << pos << "," << speed << "," << time << endl;
			if(done[pos][speed][from])
				continue;
			done[pos][speed][from] = true;
			if(pos == g && speed == 1)
			{
				ans = time;
				break;
			}
			for(size_t i = 0; i < roads[pos].size(); i++)
			{
				int npos = roads[pos][i].to;
				if(from == npos)
					continue;
				for(int ds = -1; ds <= 1; ds++)
				{
					int nspeed = speed + ds;
					if(nspeed >= 1 && nspeed <= roads[pos][i].lim && !done[npos][nspeed][pos])
					{
						double ntime = time + (double)roads[pos][i].d / nspeed;
						state nstate = state(npos, pos, nspeed, ntime);
						Q.push(nstate);
					}
				}
			}
		}
		if(ans == -1)
			cout << "unreachable" << endl;
		else
			printf("%.4f\n", ans);
	}
	return 0;
}
