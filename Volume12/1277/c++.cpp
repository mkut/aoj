#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, T, L, B;
	while(cin >> N >> T >> L >> B, N)
	{
		bool Ls[101] = {}, Bs[101] = {};
		for(int i = 0; i < L; i++)
		{
			int tmp; cin >> tmp;
			Ls[tmp] = true;
		}
		for(int i = 0; i < B; i++)
		{
			int tmp; cin >> tmp;
			Bs[tmp] = true;
		}
		
		double dp[102][101] = {};
		dp[0][0] = 1;
		
		for(int t = 1; t <= T; t++)
		{
			for(int prev = 0; prev <= N; prev++)
			{
				if(prev == N)
				{
					dp[t][N] += dp[t-1][N];
					break;
				}
				for(int j = 1; j <= 6; j++)
				{
					int next = prev+j>N ? 2*N-prev-j : prev+j;
					if(Ls[next])
						dp[t+1][next] += dp[t-1][prev]/6;
					else if(Bs[next])
						dp[t][0] += dp[t-1][prev]/6;
					else
						dp[t][next] += dp[t-1][prev]/6;
				}
			}
		}
		printf("%.6f\n", dp[T][N]);
	}
	return 0;
}
