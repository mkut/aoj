#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	const int INF = 100000000;
	int n;
	while(cin >> n, n)
	{
		vector<int> ps(n), ts(n);
		for(int i = 0; i < n; i++) cin >> ps[i] >> ts[i];
		
		if(ps[0] > ts[0]) { cout << "NG 1" << endl; continue; }
		int dp[2][3] = {{ps[0],INF,INF},{INF,INF,INF}};
		int next = 0, prev = 1;
		int ans = 0;
		for(int i = 1; i < n; i++)
		{
			swap(next, prev);
			for(int j = 0; j < 3; j++) dp[next][j] = INF;
			for(int j = 0; j < 3; j++)
			{
				if(ts[i]-ts[i-1] >= (j+2) * ps[i-1] + ps[i])
					dp[next][0] = min(dp[next][0], dp[prev][j] + ps[i-1] + ps[i]);
				if(j < 2 && ts[i]-ts[i-1] >= abs(ps[i-1] - ps[i]) * (j+2))
					dp[next][j+1] = dp[prev][j] + abs(ps[i-1] - ps[i]);
			}
			int _min = INF;
			for(int j = 0; j < 3; j++)
				_min = min(_min, dp[next][j]);
			if(_min == INF)
			{
				ans = i+1;
				break;
			}
		}
		if(ans) { cout << "NG " << ans << endl; continue; }
		
		int _min = INF;
		for(int j = 0; j < 3; j++)
			_min = min(_min, dp[next][j] + ps[n-1]);
		cout << "OK " << _min << endl;
	}
	return 0;
}
