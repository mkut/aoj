#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		vector<int> price(n);
		for(int i = 0; i < n; i++)
			cin >> price[i];
		sort(price.begin(), price.end());
		int ans = 0;
		for(int i = 0; i < n; i++)
			if(i % m != m-1)
				ans += price[n-1-i];
		cout << ans << endl;
	}
	return 0;
}
