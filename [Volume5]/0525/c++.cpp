#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<bitset<10000> > senbei(n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int tmp; cin >> tmp;
				if(tmp == 1) senbei[i][j] = true;
			}
		}
		
		int ans = 0;
		for(int i = 0; i < 1<<n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i & 1<<j)
				{
					senbei[j] = ~senbei[j];
				}
			}
			int sum = 0;
			for(int j = 0; j < m; j++)
			{
				int _sum = 0;
				for(int k = 0; k < n; k++)
				{
					if(senbei[k][j]) _sum++;
				}
				sum += max(_sum, n-_sum);
			}
			ans = max(ans, sum);
			for(int j = 0; j < n; j++)
			{
				if(i & 1<<j)
				{
					senbei[j] = ~senbei[j];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}