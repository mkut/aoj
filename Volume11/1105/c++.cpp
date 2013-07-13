#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int n, a, b;
	while(cin >> n >> a >> b, n)
	{
		vector<char> lst(n+a+b+1);
		lst[0] = 1;
		int ans = 0;
		for(int i = 0; i <= n; i++)
		{
			if(!lst[i])
				ans++;
			else
			{
				lst[i+a] = 1;
				lst[i+b] = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
