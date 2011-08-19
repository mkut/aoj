#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> edge;

int main()
{
	int n;
	cin >> n;
	int nodeno[100];
	map<edge,int> cost;
	for(int i = 0; i < n; i++)
	{
		int r, k;
		cin >> r >> k;
		nodeno[i] = r;
		while(k--)
		{
			int t;
			cin >> t;
			cost[edge(r, t)] = 1;
		}
	}
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(cost[edge(nodeno[i], nodeno[k])] == 0 || cost[edge(nodeno[k], nodeno[j])] == 0)
				{
				}
				else if(cost[edge(nodeno[i], nodeno[j])] == 0)
				{
					cost[edge(nodeno[i], nodeno[j])] = cost[edge(nodeno[i], nodeno[k])] + cost[edge(nodeno[k], nodeno[j])];
				}
				else
				{
					cost[edge(nodeno[i], nodeno[j])] = min(cost[edge(nodeno[i], nodeno[j])], cost[edge(nodeno[i], nodeno[k])] + cost[edge(nodeno[k], nodeno[j])]);
				}
			}
		}
	}
	
	int p;
	cin >> p;
	while(p--)
	{
		int s, d, v;
		cin >> s >> d >> v;
		if(cost[edge(s, d)] < v && cost[edge(s, d)] != 0) cout << cost[edge(s, d)] + 1 << endl;
		else cout << "NA" << endl;
	}
	return 0;
}