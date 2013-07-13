#include <iostream>
using namespace std;

int main()
{
	bool notprime[50000] = {};
	for(int i = 2; i < 50000; i++)
		if(!notprime[i])
			for(int j = 2; i*j < 50000; j++) 
				notprime[i*j] = true;
	
	int n = 0;
	
	while(cin >> n, n != 0)
	{
		int count = 0;
		for(int i = 2; 2*i <= n; i++)
			if(!notprime[i] && !notprime[n-i])
				count++;
		cout << count << endl;
	}
	return 0;
}