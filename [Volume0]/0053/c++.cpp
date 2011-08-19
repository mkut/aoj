#include <iostream>
using namespace std;

int main()
{
	bool _prime[1000000] = {};
	for(int i = 2; i < 1000000; i++)
	{
		if(!_prime[i])
		{
			for(int j = 2; i * j < 1000000; j++)
			{
				_prime[i*j] = true;
			}
		}
	}
	int n;
	while(cin >> n, n != 0)
	{
		int sum = 0;
		int count = 0;
		for(int i = 2; count < n; i++)
		{
			if(!_prime[i])
			{
				sum += i;
				count++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}