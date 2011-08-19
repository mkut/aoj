#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <cmath>

int main()
{
	double R;
	while(cin >> R, R != 0)
	{
		int i;
		for(i = 1; ; i++)
		{
			if(M_PI*i - floor(M_PI*i) < R*i)
			{
				cout << floor(M_PI*i) << "/" << i << endl;
				break;
			}
			if(ceil(M_PI*i) - M_PI*i < R*i)
			{
				cout << ceil(M_PI*i) << "/" << i << endl;
				break;
			}
		}
	}
	return 0;
}
