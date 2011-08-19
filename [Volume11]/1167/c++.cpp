#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int F[200] = {};
	for(int i = 0; i < 200; i++)
		F[i] = i*(i+1)*(i+2)/6;
	vector<int> dp(1000000), dp_odd(1000000);
	for(int i = 1; i < 1000000; i++)
	{
		dp[i] = 1000000;
		dp_odd[i] = 1000000;
	}
	for(int i = 1; i < 1000000; i++)
	{
		for(int j = 1; i >= F[j]; j++)
		{
			dp[i] = min(dp[i], dp[i-F[j]] + 1);
			if(F[j]&1)
			{
				dp_odd[i] = min(dp_odd[i], dp_odd[i-F[j]] + 1);
			}
		}
	}
	
	int N;
	while(cin >> N, N != 0)
	{
		cout << dp[N] << " " << dp_odd[N] << endl;
	}
}
