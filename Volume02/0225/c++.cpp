#include <iostream>
#include <algorithm>
#include <vector>
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
	while(cin >> n, n)
	{
		int begin[26] = {}, end[26] = {};
		UnionFind uf(26);
		
		while(n--)
		{
			string str; cin >> str;
			
			int x = str[0]-'a';
			int y = str[str.length()-1]-'a';
			begin[x]++;
			end[y]++;
			
			uf.unionSet(x, y);
		}
		bool ok = true;
		int uni = -1;
		for(int i = 0; i < 26; i++)
		{
			if(begin[i]+end[i] > 0)
			{
				if(uni == -1)
					uni = i;
				if(begin[i] != end[i])
					ok = false;
				if(!uf.findSet(uni, i))
					ok = false;
			}
			if(!ok)
				break;
		}
		cout << (ok ? "OK" : "NG") << endl;
	}
	return 0;
}
