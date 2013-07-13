#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
	bool notprime[10000];
	
	vector<int> prime;
	for(int i = 2; i < 10000; i++)
	{
		if(!notprime[i])
		{
			for(int j = 2; i*j < 10000; j++)
			{
				notprime[i*j] = true;
			}
			prime.push_back(i);
		}
	}
	int n;
	while(cin >> n, n != 0)
	{
		if(n == 1)
		{
			cout << "deficient number" << endl;
			continue;
		}
		unsigned long long sum = 1;
		int tmp = n;
		for(vector<int>::iterator it = prime.begin(); it != prime.end() && *it <= n; it++)
		{
			unsigned long long fct = 1;
			for(; tmp % *it == 0; tmp /= *it)
			{
				fct = fct * *it + 1;
			}
			sum *= fct;
		}
		sum *= tmp;
		sum -= n;
		
		if(sum < n)
		{
			cout << "deficient number" << endl;
		}
		else if(sum > n)
		{
			cout << "abundant number" << endl;
		}
		else
		{
			cout << "perfect number" << endl;
		}
	}
	
	return 0;
}