#include <iostream>
using namespace std;

int main()
{
	bool notprime[10000] = {};
	for(int i = 2; i < 10000; i++)
		if(!notprime[i])
			for(int j = 2; i*j < 10000; j++)
				notprime[i*j] = true;
	
	int n;
	while(cin >> n, n != 0)
	{
		for(int i = n - (n % 2 == 0 ? 1 : 0); i >= 5; i-=2)
		{
			if(!notprime[i] && !notprime[i-2])
			{
				cout << i-2 << " " << i << endl;
				break;
			}
		}
	}
	return 0;
}