#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int w, d;
	while(cin >> w >> d, w)
	{
		int hw[21] = {}, hd[21] = {};
		for(int i = 0; i < w; i++)
		{
			int tmp; cin >> tmp;
			hw[tmp]++;
		}
		for(int i = 0; i < d; i++)
		{
			int tmp; cin >> tmp;
			hd[tmp]++;
		}
		int ans = 0;
		for(int i = 1; i <= 20; i++)
			ans += i * max(hw[i], hd[i]);
		cout << ans << endl;
	}
	return 0;
}
