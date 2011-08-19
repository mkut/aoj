#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<string> vs(n);
		for(int i = 0; i < n; i++)
			cin >> vs[i];
		
		vector<vector<int> > dp(n, vector<int>(n+1));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dp[i][j] = vs[i][j] == '*' ? 0 : (i == 0 ? 1 : dp[i-1][j]+1);
		
		/*
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		*/
		
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			int height[1010], begin[1010], num = 0;
			for(int j = 0; j < n+1; j++)
			{
				bool down = false;
				while(height[num] > dp[i][j])
				{
					//cout << height[num] << "," << j-begin[num] << endl;
					ans = max(ans, min(height[num], j-begin[num]));
					num--;
					down = true;
				}
				if(height[num] < dp[i][j])
				{
					num++;
					height[num] = dp[i][j];
					if(!down)
						begin[num] = j;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
