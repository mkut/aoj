/* aoj header */
#include <vector>

int main()
{
	const int inf = 100000000;
	int n;
	while(cin >> n, n)
	{
		vector<vector<int> > time(n, vector<int>(n+1));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n+1; j++)
				cin >> time[i][j];

		vector<int> dp(1<<n, inf);
		dp[0] = 0;
		for(int i = 1; i < 1<<n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i>>j&1)
				{
					int prev = i^(1<<j);
					int min_time = time[j][0];
					for(int k = 0; k < n; k++)
						if(prev>>k&1)
							min_time = min(min_time, time[j][k+1]);
					dp[i] = min(dp[i], dp[prev] + min_time);
				}
			}
		}
		cout << dp[(1<<n)-1] << endl;
	}
	return 0;
}
