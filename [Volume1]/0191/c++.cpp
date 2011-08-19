#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		vector<vector<double> > lst(n, vector<double>(n));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> lst[i][j];
		
		vector<vector<double> > dp(2, vector<double>(n, 1.0));
		int cur = 0, prev = 1;
		for(int i = 1; i < m; i++)
		{
			for(int j = 0; j < n; j++)
				dp[cur][j] = 0.0;
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					dp[cur][j] = max(dp[cur][j], dp[prev][k] * lst[k][j]);
				}
			}
			swap(cur, prev);
		}
		double ans = 0;
		for(int i = 0; i < n; i++)
			ans = max(ans, dp[prev][i]);
		printf("%.2f\n", ans);
	}
	return 0;
}
