#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct State
{
	int pos;
	int money;
	int cost;
	
	State(int p, int m, int c)
	{
		pos = p;
		money = m;
		cost = c;
	}
	
	bool operator <(const State& a) const
	{
		return this->cost > a.cost;
	}
};

int main()
{
	int N, M, L;
	while(cin >> N >> M >> L, N != 0)
	{
		vector<vector<int> > length(N+1), cost(N+1);
		for(int i = 1; i <= N; i++)
		{
			length[i] = vector<int>(N+1);
			cost[i] = vector<int>(N+1);
		}
		for(int i = 0; i < M; i++)
		{
			int A, B, D, E;
			cin >> A >> B >> D >> E;
			length[A][B] = D;
			cost[A][B] = E;
			length[B][A] = D;
			cost[B][A] = E;
		}
		
		vector<map<int,int> > memo(N+1);
		priority_queue<State> Q;
		Q.push(State(1, L, 0));
		while(!Q.empty())
		{
			State cur = Q.top();
			Q.pop();
			if(cur.pos == N)
			{
				cout << cur.cost << endl;
				break;
			}
			for(int i = 1; i <= N; i++)
			{
				if(length[cur.pos][i] > 0)
				{
					if(memo[i].count(cur.money) == 0 || memo[i][cur.money] > cur.cost + cost[cur.pos][i])
					{
						memo[i][cur.money] = cur.cost + cost[cur.pos][i];
						Q.push(State(i, cur.money, cur.cost + cost[cur.pos][i]));
					}
					if(cur.money >= length[cur.pos][i] && (memo[i].count(cur.money - length[cur.pos][i]) == 0 || memo[i][cur.money - length[cur.pos][i]] > cur.cost))
					{
						memo[i][cur.money - length[cur.pos][i]] = cur.cost;
						Q.push(State(i, cur.money - length[cur.pos][i], cur.cost));
					}
				}
			}
		}
	}
	return 0;
}
