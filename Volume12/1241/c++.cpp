#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int dp[1<<15][5] = {};
	dp[0][0] = 1;
	for(int k = 1; k*k < 1<<15; k++)
		for(int j = 1; j <= 4; j++)
			for(int i = k*k; i < 1<<15; i++)
				dp[i][j] += dp[i-k*k][j-1];
	
	int n;
	while(cin >> n, n != 0)
	{
		int ans = 0;
		for(int i = 1; i <= 4; i++)
		{
			ans += dp[n][i];
		}
		cout << ans << endl;
	}
	return 0;
}
