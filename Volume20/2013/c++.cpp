#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<string,int> a, pair<string,int> b)
{
	return a.first < b.first;
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<pair<string,int> > dia;
		for(int i = 0; i < n; i++)
		{
			string a, b; cin >> a >> b;
			dia.push_back(pair<string,int>(a, 1));
			dia.push_back(pair<string,int>(b, -1));
		}
		sort(dia.begin(), dia.end());
		
		int ans = 0;
		int cur = 0;
		for(int i = 0; i < 2*n; i++)
		{
			cur += dia[i].second;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}
