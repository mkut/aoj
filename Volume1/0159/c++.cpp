#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int bestnum;
		double bestdif = 1e8;
		for(int i = 0; i < n; i++)
		{
			int number, h, w;
			cin >> number >> h >> w;
			if(bestdif > fabs(w*1e4/h/h-22))
			{
				bestnum = number;
				bestdif = fabs(w*1e4/h/h-22);
			}
		}
		cout << bestnum << endl;
	}
	
	return 0;
}