#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<vector<int> > building(2, vector<int>(n)), dp(2, vector<int>(n, 100000000));
		dp[0][0] = 0; dp[1][0] = 0;
		for(int i = 0; i < 2*n; i++)
			cin >> building[i/n][i%n];
		for(int i = 1; i < n; i++)
			for(int j = 0; j < 2; j++)
			{
				if(building[j][i] == 2) continue;
				if(true) dp[j][i] = min(dp[j][i], dp[1-j][i] + 1);
				if(i >= 1) dp[j][i] = min(dp[j][i], dp[1-j][i-1] + 1);
				if(i >= 2) dp[j][i] = min(dp[j][i], dp[1-j][i-2] + 1);
				if(building[j][i] == 1 && building[j][i-1] == 1) dp[j][i] = min(dp[j][i], dp[j][i-1]);
			}
		
		int ans = min(dp[0][n-1], dp[1][n-1]);
		if(ans == 100000000)
			cout << "NA" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
