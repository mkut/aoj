#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	int city, m;
	node(int City, int M) : city(City), m(M) {}
	
	bool operator<(const node& a) const
	{
		return city < a.city || city == a.city && m < a.m;
	}
};

struct state
{
	node n;
	int time;
	state(node N, int Time) : n(N), time(Time) {}
	state(int City, int M, int Time) : n(City, M), time(Time) {}
	
	bool operator<(const state& a) const
	{
		return time > a.time;
	}
};

int main()
{
	int N, M, L, K, A, H;
	while(cin >> N >> M >> L >> K >> A >> H, N)
	{
		vector<char> freeze(N);
		freeze[A] = freeze[H] = 1;
		for(int i = 0; i < L; i++)
		{
			int tmp; cin >> tmp;
			freeze[tmp] = 1;
		}
		vector<vector<int> > path(N), length(N);
		for(int i = 0; i < K; i++)
		{
			int X, Y, T; cin >> X >> Y >> T;
			path[X].push_back(Y); length[X].push_back(T);
			path[Y].push_back(X); length[Y].push_back(T);
		}
		
		priority_queue<state> Q;
		bool done[100][101] = {};
		vector<vector<int> > cost(N, vector<int>(M+1, 1<<20));
		Q.push(state(A, M, 0));
		done[A][M] = true;
		bool ok = false;
		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			//cout << cur.n.city << "," << cur.n.m << "," << cur.time << endl;
			if(cur.n.city == H)
			{
				cout << cur.time << endl;
				ok = true;
				break;
			}
			done[cur.n.city][cur.n.m] = true;
			for(int i = 0; i < path[cur.n.city].size(); i++)
			{
				if(cur.n.m >= length[cur.n.city][i])
				{
					node nn = node(path[cur.n.city][i], cur.n.m - length[cur.n.city][i]);
					state next = state(nn, cur.time + length[cur.n.city][i]);
					if(!done[nn.city][nn.m] && cost[nn.city][nn.m] > next.time)
					{
						cost[nn.city][nn.m] = next.time;
						Q.push(next);
					}
				}
			}
			if(freeze[cur.n.city] && cur.n.m != M)
			{
				node nn = node(cur.n.city, cur.n.m + 1);
				state next = state(nn, cur.time + 1);
				if(!done[nn.city][nn.m] && cost[nn.city][nn.m] > next.time)
				{
					cost[nn.city][nn.m] = next.time;
					Q.push(next);
				}
			}
		}
		
		if(!ok) cout << "Help!" << endl;
	}
	return 0;
}
