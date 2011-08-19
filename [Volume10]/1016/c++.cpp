#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int V, d;
	while(cin >> V >> d)
	{
		vector<int> fib(V);
		fib[0] = 2;
		if(V > 1) fib[1] = 3;
		for(int i = 2; i < V; i++)
		{
			fib[i] = (fib[i-1] + fib[i-2])%1001;
		}
		
		sort(fib.begin(), fib.end());
		
		int ans = 1;
		for(int i = 0; i < V-1; i++)
		{
			if(fib[i+1] - fib[i] >= d)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}