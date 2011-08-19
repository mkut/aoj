#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int f[31]; f[1] = 1;
	for(int i = 2; i <= 30; i++)
	{
		f[i] = f[i-1]*3+1;
	}
	
	int ans[31];
	ans[1] = 1; ans[2] = 2;
	for(int i = 3; i <= 30; i++)
	{
		int res = i;
		for(int j = 1; j < i-1; j++)
		{
			res += f[min(j, i-j-1)]*2;
		}
		ans[i] = res;
	}
	
	int n;
	while(cin >> n) cout << ans[n] << endl;
	
	return 0;
}