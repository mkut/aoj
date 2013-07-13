#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int sum = 0;
		vector<int> lst(n);
		for(int i = 0; i < n; i++) {cin >> lst[i]; sum+= lst[i];}
		vector<vector<int> > ans(n);
		ans[0].push_back(0);
		ans[0].push_back(lst[0]);
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < ans[i-1].size(); j++)
			{
				ans[i].push_back(ans[i-1][j]);
				if(ans[i-1][j]+lst[i] <= sum/2)
				{
					ans[i].push_back(ans[i-1][j]+lst[i]);
				}
			}
		}
		int _min = sum;
		for(int i = 0; i < ans[n-1].size(); i++)
		{
			_min = min(_min, abs(sum - ans[n-1][i]*2));
		}
		cout << _min << endl;
	}
	return 0;
}