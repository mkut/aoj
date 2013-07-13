#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	while(cin >> N >> M)
	{
		vector<int> C(N);
		vector<int> State[3] = {vector<int>(N), vector<int>(N), vector<int>(N)};
		for(int i = 0; i < N; i++)
		{
			string name;
			getline(cin, name);
			getline(cin, name);
			cin >> C[i] >> State[0][i] >> State[1][i] >> State[2][i];
		}
		int ans = 0;
		for(int i = 0; i < 3; i++)
		{
			vector<int> dp(M+1);
			for(int j = 1; j <= M; j++)
			{
				dp[j] = dp[j-1];
				for(int k = 0; k < N; k++)
				{
					if(j-C[k] >= 0)
						dp[j] = max(dp[j],dp[j-C[k]] + State[i][k]);
				}
			}
			ans = max(ans, dp[M]);
		}
		cout << ans << endl;
	}
	return 0;
}
