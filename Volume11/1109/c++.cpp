#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int z;
	while(cin >> z, z)
	{
		int ans = 0;
		for(int x = 1; x*x*x < z*z*z; x++)
			for(int y = x; x*x*x + y*y*y <= z*z*z; y++)
				ans = max(ans, x*x*x + y*y*y);
		cout << z*z*z - ans << endl;
	}
	return 0;
}
