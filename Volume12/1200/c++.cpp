#include <iostream>
using namespace std;

int main()
{
	bool notprime[32768] = {};
	for(int i = 2; i < 32768; i++)
		if(!notprime[i])
			for(int j = 2; i*j < 32768; j++)
				notprime[i*j] = true;
	
	int n;
	while(cin >> n, n != 0)
	{
		int ans = 0;
		for(int i = 2; i*2 <= n; i++)
		{
			if(!notprime[i] && !notprime[n-i]) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}