#include <iostream>
using namespace std;

int main()
{
	bool _prime[60000] = {};
	for(int i = 2; i < 60000; i++)
	{
		if(!_prime[i])
		{
			for(int j = 2; j * i < 60000; j++)
			{
				_prime[i*j] = true;
			}
		}
	}
	
	int n;
	while(cin >> n)
	{
		int i;
		for(i = n-1; _prime[i]; i--){}
		cout << i;
		for(i = n+1; _prime[i]; i++){}
		cout << " " << i << endl;
	}
	return 0;
}