#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void visit(vector<vector<int> >& g, int v, vector<vector<short> >& scc, stack<int>& S,
			  vector<char>& inS, vector<int>& low, vector<int>& num, int& time)
{
	low[v] = num[v] = ++time;
	S.push(v); inS[v] = true;
	for(int i = 0; i < 2; ++i)
	{
		int w = g[v][i];
		
		if(num[w] == 0)
		{
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if(inS[w])
		{
			low[v] = min(low[v], low[w]);
		}
	}
	if(low[v] == num[v])
	{
		scc.push_back(vector<short>());
		while(true)
		{
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if(v == w) break;
		}
	}
}

void stronglyConnectedComponents(vector<vector<int> >& graph, vector<vector<short> >& scc)
{
	int n = graph.size();
	vector<int> num(n), low(n);
	stack<int> S;
	vector<char> inS(n);
	int time = 0;
	for(int i = 0; i < n; i++)
		if(num[i] == 0)
			visit(graph, i, scc, S, inS, low, num, time);
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<vector<int> > graph(n, vector<int>(2));
		vector<vector<int> > cost(n, vector<int>(2));
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				int I, B;
				cin >> I >> B;
				graph[i][j] = I;
				cost[i][j] = B;
			}
		}
		
		vector<vector<short> > scc;
		stronglyConnectedComponents(graph, scc);
		
		int ans = 1;
		for(int i = 0; i < scc.size(); i++)
		{
			int Max = 0, num = 0;
			for(int j = 0; j < scc[i].size(); j++)
			{
				for(int k = 0; k < 2; k++)
				{
					if(Max < cost[scc[i][j]][k])
					{
						Max = cost[scc[i][j]][k];
						num = 1;
					}
					else if(Max == cost[scc[i][j]][k])
					{
						num++;
					}
				}
			}
			ans *= num/2;
			ans %= 10007;
		}
		cout << ans << endl;
	}
	return 0;
}
