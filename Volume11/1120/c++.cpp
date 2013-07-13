#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
	vector<int> down, up;
	void put_off(int a)
	{
		if(a == 0) return;
		up[down[a]] = 0;
		down[a] = 0;
		put_off(up[a]);
	}
	void put_on(int a, int b)
	{
		if(up[b] == 0)
			up[b] = a, down[a] = b;
		else
			put_on(a, up[b]);
	}
	void put(int a, int b)
	{
		put_off(a);
		put_on(a, b);
	}
	bool search_dir(int a, int b, vector<int>& dir)
	{
		if(a == b) return true;
		if(a == 0) return false;
		return search_dir(dir[a], b, dir);
	}
	int search(int a, int b)
	{
		if(search_dir(a, b, down)) return -1;
		if(search_dir(a, b, up)) return 1;
		return 0;
	}
	int size_delete(int a, vector<char>& done)
	{
		if(a == 0) return 0;
		if(done[a]) return 0;
		done[a] = 1;
		return size_delete(up[a], done) + size_delete(down[a], done) + 1;
	}
public:
	solver(int size) : down(size), up(size) {}
	void try_put(int a, int b)
	{
		if(a == b) return;
		if(b == 0 && down[a] == 0) return;
		if(b == 0) { put_off(a); return; }
		if(search(a, b) == -1) return;
		put(a, b);
	}
	vector<int> result()
	{
		vector<int> ret;
		vector<char> done(down.size());
		for(int i = 1; i < down.size(); i++)
		{
			int size = size_delete(i, done);
			if(size > 0)
				ret.push_back(size);
		}
		sort(ret.begin(), ret.end());
		return ret;
	}
};

int main()
{
	int m;
	while(cin >> m, m)
	{
		solver prob(m+1);
		int i, j;
		while(cin >> i >> j, i || j)
			prob.try_put(i, j);
		vector<int> ans = prob.result();
		for(int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
		cout << "end" << endl;
	}
	return 0;
}
