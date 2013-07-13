#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

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
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
};

struct edge
{
	int a, b;
	double d;
	edge(int a, int b, double d) : a(a), b(b), d(d) {}
	bool operator<(const edge& c) const { return d < c.d; }
};

double norm(double x, double y, double z)
{ return sqrt(x*x + y*y + z*z); }

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<double> x(n), y(n), z(n), r(n);
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> z[i] >> r[i];
		
		vector<edge> es;
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				es.push_back(edge(i, j, max(0.0, norm(x[i]-x[j], y[i]-y[j], z[i]-z[j]) - r[i] - r[j])));
		
		sort(es.begin(), es.end());
		UnionFind uf(n);
		double ans = 0;
		for(int i = 0; i < es.size(); i++)
			if(uf.unionSet(es[i].a, es[i].b))
				ans += es[i].d;
		printf("%.3f\n", ans);
	}
	return 0;
}
