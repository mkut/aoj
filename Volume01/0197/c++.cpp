#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int x, y;
	while(cin >> x >> y, x)
	{
		if(x < y) swap(x, y);
		
		int step = 0;
		while(y)
		{
			x %= y;
			swap(x, y);
			step++;
		}
		cout << x << " " << step << endl;
	}
	return 0;
}
