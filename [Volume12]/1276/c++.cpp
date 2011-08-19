#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	bool notprime[1300000] = {};
	vector<int> primes;
	for(int i = 2; i < 1300000; i++)
		if(!notprime[i])
		{
			primes.push_back(i);
			for(int j = i+i; j < 1300000; j += i)
				notprime[j] = true;
		}
	
	int n;
	while(cin >> n, n)
	{
		int i = 0;
		while(primes[i] < n)
			i++;
		
		cout << (primes[i] == n ? 0 : primes[i] - primes[i-1]) << endl;
	}
	return 0;
}
