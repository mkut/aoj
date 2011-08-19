#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	bool notprime[12000] = {};
	vector<int> primes;
	for(int i = 2; i < 12000; i++)
	{
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = i+i; j < 12000; j+=i)
				notprime[j] = true;
		}
	}
	
	int n;
	while(cin >> n, n)
	{
		int ans = 0;
		for(int i = 0; primes[i] <= n; i++)
		{
			int sum = 0;
			for(int j = i; sum < n; j++)
				sum += primes[j];
			if(sum == n)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
