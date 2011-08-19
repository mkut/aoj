#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int e;
	while(cin >> e, e)
	{
		int m = e;
		for(int z = 0; z*z*z <= e; z++)
			for(int y = 0; z*z*z+y*y <= e; y++)
				m = min(m, z + y + e-z*z*z-y*y);
		cout << m << endl;
	}
	return 0;
}
