#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000;

struct UnionFind
{
	vector<int> data;
	UnionFind(int size) : data(size, -1) {}
	bool unionSet(int x, int y)
	{
		x = root(x); y = root(y);
		if(x == y) return false;
		if(data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
	bool findSet(int x, int y)
	{
		return root(x) == root(y);
	}
	int root(int x)
	{
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
};

struct edge
{
	int a, b, d;
	edge(int a, int b, int d) : a(a), b(b), d(d) {}
	bool operator<(const edge& e) const { return d < e.d; }
};

int main()
{
	int s, d;
	while(cin >> s >> d, s)
	{
		vector<edge> edges;
		for(int i = 0; i < s; i++)
		{
			for(int j = 1; j <= d; j++)
			{
				int dist; cin >> dist;
				if(dist == 0) dist = INF;
				edges.push_back(edge(0, j, dist));
			}
		}
		for(int i = 1; i <= d; i++)
		{
			for(int j = i+1; j <= d; j++)
			{
				int dist; cin >> dist;
				if(dist == 0) dist = INF;
				edges.push_back(edge(i, j, dist));
			}
		}
		
		UnionFind uf(d+1);
		sort(edges.begin(), edges.end());
		int ans = 0;
		for(int i = 0; i < edges.size(); i++)
			if(uf.unionSet(edges[i].a, edges[i].b))
				ans += edges[i].d;
		cout << ans << endl;
	}
	return 0;
}
