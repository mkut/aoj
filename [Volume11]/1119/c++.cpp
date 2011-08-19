#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int x = 0, y = 0;
		int max_d2 = 0, max_x = 0, max_y = 0;
		int dx, dy;
		while(cin >> dx >> dy, dx || dy)
		{
			x += dx; y += dy;
			if(max_d2 < x*x + y*y || max_d2 == x*x + y*y && max_x < x)
				max_d2 = x*x + y*y, max_x = x, max_y = y;
		}
		cout << max_x << " " << max_y << endl;
	}
	return 0;
}
