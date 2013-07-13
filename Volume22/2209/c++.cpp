#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool iszero(char c) { return c == '0' || c == 'x'; }
bool isone(char c) { return c == '1' || c == 'x'; }

int py(char a, char b, char c, char d, char e)
{
	bool allzero = a != '1' && b != '1' && c != '1' && d != '1' && e != '1';
	int shift = (a == 'x' ? 1 : 0) + (b == 'x' ? 1 : 0) + (c == 'x' ? 1 : 0) + (d == 'x' ? 1 : 0) + (e == 'x' ? 1 : 0);
	return (1 << shift) - (allzero ? 1 : 0);
}

int main()
{
	int N;
	int DIV = 1000000;
	while(cin >> N, N)
	{
		vector<string> bits(N);
		for(int i = 0; i < N; i++) cin >> bits[i];
		
		vector<long long> dp(N+1);
		dp[0] = 1;
		for(int i = 0; i < N; i++)
		{
			if(i < N && iszero(bits[i][0]))
			{
				int shift = 0;
				for(int j = 1; j < 8; j++) if(bits[i][j] == 'x') shift++;
				dp[i+1] += dp[i] << shift;
				dp[i+1] %= DIV;
			}
			if(i + 1 < N && isone(bits[i][0]) && isone(bits[i][1]) && iszero(bits[i][2])
					&& isone(bits[i+1][0]) && iszero(bits[i+1][1]))
			{
				int _py = py(bits[i][3], bits[i][4], bits[i][5], bits[i][6], '0');
				int shift = bits[i][7] == 'x' ? 1 : 0;
				for(int j = 2; j < 8; j++) if(bits[i+1][j] == 'x') shift++;
				dp[i+2] += (dp[i] * _py) << shift;
				dp[i+2] %= DIV;				
			}
			if(i + 2 < N && isone(bits[i][0]) && isone(bits[i][1]) && isone(bits[i][2]) && iszero(bits[i][3])
					&& isone(bits[i+1][0]) && iszero(bits[i+1][1])
					&& isone(bits[i+2][0]) && iszero(bits[i+2][1]))
			{
				int _py = py(bits[i][4], bits[i][5], bits[i][6], bits[i][7], bits[i+1][2]);
				int shift = 0;
				for(int j = 3; j < 8; j++) if(bits[i+1][j] == 'x') shift++;
				for(int j = 2; j < 8; j++) if(bits[i+2][j] == 'x') shift++;
				dp[i+3] += (dp[i] * _py) << shift;
				dp[i+3] %= DIV;				
			}
			if(i + 3 < N && isone(bits[i][0]) && isone(bits[i][1]) && isone(bits[i][2]) && isone(bits[i][3]) && iszero(bits[i][4])
					&& isone(bits[i+1][0]) && iszero(bits[i+1][1])
					&& isone(bits[i+2][0]) && iszero(bits[i+2][1])
					&& isone(bits[i+3][0]) && iszero(bits[i+3][1]))
			{
				int _py = py(bits[i][5], bits[i][6], bits[i][7], bits[i+1][2], bits[i+1][3]);
				int shift = 0;
				for(int j = 4; j < 8; j++) if(bits[i+1][j] == 'x') shift++;
				for(int j = 2; j < 8; j++) if(bits[i+2][j] == 'x') shift++;
				for(int j = 2; j < 8; j++) if(bits[i+3][j] == 'x') shift++;
				dp[i+4] += (dp[i] * _py) << shift;
				dp[i+4] %= DIV;				
			}
		}
		//for(int i = 0; i < N; i++)
		//	cout << dp[i] << endl;
		cout << dp[N] << endl;
	}
	return 0;
}
