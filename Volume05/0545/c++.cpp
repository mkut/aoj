#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

void solve(vector<vector<int> >& friends, int person, int rem, vector<char>& res)
{
	res[person] = true;
	for(int i = 0; i < friends[person].size(); i++)
	{
		res[friends[person][i]] += true;
		if(rem > 1)
			solve(friends, friends[person][i], rem-1, res);
	}
}

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		vector<vector<int> > friends(n);
		for(int i = 0; i < m; i++)
		{
			int a, b; cin >> a >> b;
			a--; b--;
			friends[a].push_back(b);
			friends[b].push_back(a);
		}
		
		vector<char> fr(n);
		solve(friends, 0, 2, fr);
		
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(fr[i])
				ans++;
		
		cout << ans-1 << endl;
	}
	return 0;
}
