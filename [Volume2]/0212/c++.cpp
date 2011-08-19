#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct state
{
	int pos, cost, coupon;
	
	state(int Pos, int Cost, int Coupon) : pos(Pos), cost(Cost), coupon(Coupon) {}
	
	bool operator<(const state& a) const
	{
		return cost > a.cost;
	}
};

int main()
{
	int c, n, m, s, d;
	while(cin >> c >> n >> m >> s >> d, n)
	{
		s--; d--;
		
		vector<vector<int> > adj(n), fare(n);
		for(int i = 0; i < m; i++)
		{
			int a, b, f;
			cin >> a >> b >> f;
			a--; b--;
			adj[a].push_back(b); fare[a].push_back(f);
			adj[b].push_back(a); fare[b].push_back(f);
		}
		
		priority_queue<state> Q;
		vector<vector<int> > memo(n, vector<int>(c+1, 100000000));
		Q.push(state(s, 0, c));
		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			if(cur.pos == d)
			{
				cout << cur.cost << endl;
				break;
			}
			if(memo[cur.pos][cur.coupon] < cur.cost)
				continue;
			for(int i = 0; i <= cur.coupon; i++)
				memo[cur.pos][i] = min(memo[cur.pos][i], cur.cost);
			for(int i = 0; i < adj[cur.pos].size(); i++)
			{
				Q.push(state(adj[cur.pos][i], cur.cost + fare[cur.pos][i], cur.coupon));
				if(cur.coupon) Q.push(state(adj[cur.pos][i], cur.cost + fare[cur.pos][i]/2, cur.coupon-1));
			}
		}
	}
	return 0;
}
