#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
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
	bool findSet(int x, int y)
	{
		return root(x) == root(y);
	}
	int root(int x)
	{
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
};

int main()
{
	int n;
	while(cin >> n)
	{
		UnionFind uf(7);
		vector<string> dominoes(n);
		for(int i= 0; i < n; i++)
			cin >> dominoes[i];
		vector<int> num(7);
		for(int i = 0; i < n; i++)
		{
			int a = dominoes[i][0]-'0';
			int b = dominoes[i][1]-'0';
			num[a]++;
			num[b]++;
			uf.unionSet(a, b);
		}
		int odd = 0;
		for(int i = 0; i < 7; i++)
			odd += num[i]%2;
		
		int Min = 0;
		while(num[Min] == 0) Min++;
		bool linked = true;
		for(int i = Min+1; i < 7; i++)
			linked &= num[i] == 0 || uf.findSet(Min, i);
		cout << (odd <= 2 && linked ? "Yes" : "No") << endl;
	}
	
	return 0;
}
