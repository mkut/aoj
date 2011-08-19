#include <iostream>
#include <algorithm>
using namespace std;

int noc(int money)
{
	return money / 500 + money % 500 / 100 + money % 100 / 50 + money % 50 / 10 + money % 10 / 5 + money % 5;
}

int main()
{
	int P, N[6], price[6] = {1,5,10,50,100,500};
	while(cin >> P >> N[0] >> N[1] >> N[2] >> N[3] >> N[4] >> N[5], P != 0)
	{
		int sum = 0, coin = 0, _min = 10000;
		for(int n = 5; n >= 0; n--)
		{
			while(N[n] > 0)
			{
				N[n]--;
				sum += price[n];
				coin++;
				if(P <= sum)
				{
					_min = min(_min, coin + noc(sum-P));
					coin--;
					sum -= price[n];
					break;
				}
			}
		}
		cout << _min << endl;
	}
	return 0;
}