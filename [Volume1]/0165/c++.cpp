#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	bool notprime[1000000] = {};
	vector<int> primes;
	for(int i = 2; i < 1000000; i++)
	{
		if(!notprime[i])
		{
			for(int j = 2; i*j < 1000000; j++)
			{
				notprime[i*j] = true;
			}
			primes.push_back(i);
		}
	}
	
	int n;
	while(cin >> n, n != 0)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int p, m;
			cin >> p >> m;
			int cost = -1;
			for(int i = 0; i < primes.size(); i++)
			{
				if(primes[i] > p+m) break;
				if(primes[i] >= p-m && primes[i] <= p+m)
				{
					cost++;
				}
			}
			sum += cost;
		}
		cout << max(sum, 0) << endl;
	}
	return 0;
}