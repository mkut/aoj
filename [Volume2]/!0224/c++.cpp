#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

// Dijkstra Ç∂Ç·ÇæÇﬂ
// Bellman-Ford Ç…Ç∑ÇÈ Å® ä‘Ç…çáÇÌÇ»Ç¢
// Dijkstra Ç≈ç≈å„Ç‹Ç≈

#define INF 1000000

struct State
{
	int pos, eaten;
	State(int Pos, int Eaten) : pos(Pos), eaten(Eaten) {}
	bool operator<(const State& a) const
	{
		return pos < a.pos || pos == a.pos && eaten < a.eaten;
	}
};

struct DState
{
	int cost;
	State state;
	DState(int Cost, State st) : cost(Cost), state(st) {}
	
	bool operator<(const DState& a) const
	{
		return cost > a.cost;
	}
};

int main()
{
	int m, n, k, d;
	while(cin >> m >> n >> k >> d, m)
	{
		vector<int> cakes(m);
		for(int i = 0; i < m; i++)
			cin >> cakes[i];
		
		vector<vector<int> > dst(m+n+2, vector<int>(m+n+2, INF));
		for(int i = 0; i < d; i++)
		{
			string A, B;
			int iA, iB, d;
			cin >> A >> B >> d;
			iA = A.length() == 1 ? (A[0] == 'H' ? 0 : 1) : (A[0] == 'C' ? atoi(A.c_str()+1)+1 : atoi(A.c_str()+1)+m+1);
			iB = B.length() == 1 ? (B[0] == 'H' ? 0 : 1) : (B[0] == 'C' ? atoi(B.c_str()+1)+1 : atoi(B.c_str()+1)+m+1);
			dst[iA][iB] = min(dst[iA][iB], d);
			dst[iB][iA] = min(dst[iB][iA], d);
		}
		
		priority_queue<DState> Q;
		bool done[64][108] = {};
		Q.push(DState(0, State(0, 0)));
		int ans = INF;
		while(!Q.empty())
		{
			DState cds = Q.top(); Q.pop();
			if(done[cds.state.eaten][cds.state.pos])
				continue;
			done[cds.state.eaten][cds.state.pos] = true;
			cout << cds.cost << ":" << cds.state.pos << "," << cds.state.eaten << endl;
			if(cds.state.pos == 1)
			{
				ans = min(ans, cds.cost);
			}
			for(int i = 0; i < m+n+2; i++)
			{
				if(dst[cds.state.pos][i] != INF)
				{
					if(i >= 2 && i < 2+m && (cds.state.eaten>>i-2 & 1))
						continue;
					State nstate(i, cds.state.eaten);
					if(i >= 2 && i < 2+m)
						nstate.eaten |= 1<<i-2;
					
					Q.push(DState(cds.cost + dst[cds.state.pos][i] * k - (i >= 2 && i < 2+m ? cakes[i-2] : 0), nstate));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
