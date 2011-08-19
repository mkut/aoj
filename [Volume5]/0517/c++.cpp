#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	int n, k;
	while(cin >> n >> k, n != 0)
	{
		vector<int> vi(k);
		for(int i = 0; i < k; i++)
		{
			cin >> vi[i];
		}
		
		sort(vi.begin(), vi.end());
		
		int ans = 0;
		if(vi[0] != 0)
		{
			int cur = 1;
			for(int i = 1; i < k; i++)
			{
				if(vi[i] - vi[i-1] == 1)
				{
					cur++;
					ans = max(ans, cur);
				}
				else cur = 1;
			}
		}
		else
		{
			vector<int> anslst;
			int cur = 1;
			for(int i = 2; i < k; i++)
			{
				if(vi[i] - vi[i-1] == 1)
				{
					cur++;
					if(i == k-1) anslst.push_back(cur);
				}
				else
				{
					anslst.push_back(cur);
					if(vi[i] - vi[i-1] != 2) anslst.back() *= -1;
					cur = 1;
				}
			}
			ans = anslst[0]+1;
			for(int i = 1; i < anslst.size(); i++)
			{
				if(anslst[i-1] < 0) ans = max(ans, abs(anslst[i]));
				else ans = max(ans, abs(anslst[i]) + abs(anslst[i-1]) + 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}