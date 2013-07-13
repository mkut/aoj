#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> MSprime;
	for(int i = 6; i < 300000; )
	{
		bool prime = true;
		for(int j = 0; j < MSprime.size(); j++)
		{
			if(MSprime[j] * MSprime[j] > i)
				break;
			if(i % MSprime[j] == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime)
			MSprime.push_back(i);
		
		if(i % 7 == 6)
			i += 2;
		else
			i += 5;
	}
	
	int n;
	while(cin >> n, n != 1)
	{
		cout << n << ":";
		for(int i = 0; i < MSprime.size(); i++)
			if(n % MSprime[i] == 0)
				cout << " " << MSprime[i];
		cout << endl;
	}
	return 0;
}
