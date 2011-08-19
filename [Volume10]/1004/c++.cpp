#include <iostream>
using namespace std;

int main()
{
	bool notprime[10001] = {true, true};
	for(int i = 2; i < 10001; i++)
		if(!notprime[i])
			for(int j = 2; i*j < 10001; j++)
				notprime[i*j] = true;
	
	int n;
	while(cin >> n)
	{
		int count = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!notprime[i] && !notprime[n+1-i]) count++;
		}
		cout << count << endl;
	}
	
	return 0;
}