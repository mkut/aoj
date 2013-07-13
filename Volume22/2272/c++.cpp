/* aoj header */
#include <vector>

int main()
{
	int H, W; cin >> H >> W;
	vector<string> semi(H);
	for(int i = 0; i < H; i++)
		cin >> semi[i];
	vector<vector<int> > dp(H+1, vector<int>(W+1, 1000000));
	dp[0][1] = dp[1][0] = 0;
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j]) + semi[i][j] - '0';
	cout << dp[H][W] << endl;
}
