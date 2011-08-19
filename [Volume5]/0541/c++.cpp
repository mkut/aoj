#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int H, W, N;
	while(cin >> H >> W >> N, H)
	{
		vector<vector<int> > dir(H+1, vector<int>(W+1)), dp(H+1, vector<int>(W+1));
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= W;j++)
				cin >> dir[i][j];
		
		dp[1][1] = N-1;
		for(int i = 1; i <= H; i++)
			for(int j = 1; j <= W; j++)
				dp[i][j] += (dp[i][j-1] + dir[i][j-1])/2 + (dp[i-1][j] + 1 - dir[i-1][j])/2;
		
		int x = 1, y = 1;
		while(x <= H && y <= W)
		{
			if((dir[x][y] + dp[x][y])%2)
				y++;
			else
				x++;
		}
		cout << x << " " << y << endl;
	}
	return 0;
}
