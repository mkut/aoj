#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct _state
{
	int oxy, x, y;
	_state(int oxy, int x, int y) : oxy(oxy), x(x), y(y) {}
	bool operator<(const _state& a) const
	{ return oxy < a.oxy || oxy == a.oxy && x < a.x || oxy == a.oxy && x == a.x && y < a.y; }
};

struct state
{
	int cost;
	_state node;
	state(int cost, _state node)
		: cost(cost), node(node) {}
	bool operator<(const state& a) const { return cost > a.cost; }
};

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

int main()
{
	int W, H;
	while(cin >> W >> H, W)
	{
		int f, m, o; cin >> f >> m >> o;
		vector<vector<int> > c(H, vector<int>(W));
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
				cin >> c[i][j];
		
		priority_queue<state> Q;
		set<_state> done;
		for(int i = 0; i < W; i++)
		{
			int cost = c[0][i] < 0 ? -c[0][i] : 0;
			int oxy = min(o - 1 + (c[0][i] > 0 ? c[0][i] : 0), m);
			Q.push(state(cost, _state(oxy, 0, i)));
		}
		int ans = -1;
		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			_state _cur = cur.node;
			int cost = cur.cost;
			int x = _cur.x, y = _cur.y, oxy = _cur.oxy;
			if(cost > f) break;
			if(oxy >= 1 && x == H-1) { ans = cost; break; }
			if(done.count(_cur)) continue;
			done.insert(_cur);
			if(oxy >= 2)
			{
				for(int i = 0; i < 4; i++)
				{
					int next_x = x + dx[i];
					int next_y = y + dy[i];
					if(next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
					int next_cost = cost + (c[next_x][next_y] < 0 ? -c[next_x][next_y] : 0);
					int next_oxy = min(oxy - 1 + (c[next_x][next_y] > 0 ? c[next_x][next_y] : 0), m);
					Q.push(state(next_cost, _state(next_oxy, next_x, next_y)));
				}
			}
		}
		if(ans == -1)
			cout << "NA" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
