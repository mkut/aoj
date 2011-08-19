#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int id(int x)
{
	return x;
}

struct state
{
	int x, y, dir;
	
	state()
	{
		x = 0;
		y = 0;
		dir = 0;
	}
	state(int X, int Y, int Dir)
	{
		x = X;
		y = Y;
		dir = Dir;
	}
	
	bool operator<(const state& b) const
	{
		return x < b.x || x == b.x && y < b.y || x == b.x && y == b.y && dir < b.dir;
	}
};
bool operator<(const pair<state,int>& a, const pair<state,int>& b)
{
	return a.second > b.second;
}

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		priority_queue<pair<state,int> > linked;
		set<state> done;
		vector<vector<int> > tile(h);
		for(int i = 0; i < h; i++)
		{
			tile[i] = vector<int>(w);
			for(int j = 0; j < w; j++)
				cin >> tile[i][j];
		}
		int cost[4];
		for(int i = 0; i < 4; i++)
			cin >> cost[i];
		
		int dx[] = {1,0,-1,0};
		int dy[] = {0,1,0,-1};
		
		linked.push(pair<state,int>(state(0,0,0),0));
		while(!linked.empty())
		{
			pair<state,int> cur = linked.top();
			linked.pop();
			done.insert(done.begin(), cur.first);
			if(cur.first.x < 0 || cur.first.x >= w || cur.first.y < 0 || cur.first.y >= h)
				continue;
			if(cur.first.x == w-1 && cur.first.y == h-1)
			{
				cout << cur.second << endl;
				break;
			}
			
			for(int i = 0; i < 4; i++)
			{
				int ncost = cur.second + (tile[cur.first.y][cur.first.x] == i ? 0 : cost[i]);
				int ndir = (cur.first.dir + i) % 4;
				state nstate = state(cur.first.x + dx[ndir], cur.first.y + dy[ndir], ndir);
				if(done.count(nstate) == 0)
				{
					linked.push(pair<state,int>(nstate, ncost));
				}
			}
		}
	}
	return 0;
}
