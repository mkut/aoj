#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N)
	{
		int W, H; cin >> W >> H;
		vector<vector<int> > cnt(H, vector<int>(W));
		vector<int> x(N), y(N);
		for(int i = 0; i < N; i++)
			cin >> x[i] >> y[i], x[i]--, y[i]--;
		int S, T; cin >> S >> T;
		
		for(int k = 0; k < N; k++)
			for(int i = y[k]; i < min(H, y[k]+T); i++)
				for(int j = x[k]; j < min(W, x[k]+S); j++)
					cnt[i][j]++;
		
		int ans = 0;
		for(int i = T-1; i < H; i++)
			for(int j = S-1; j < W; j++)
				ans = max(ans, cnt[i][j]);
		
		cout << ans << endl;
	}
	return 0;
}
