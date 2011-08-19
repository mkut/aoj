#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int b, r, g, c, s, t;
	while(cin >> b >> r >> g >> c >> s >> t, t)
	{
		int ans = 100 - 3*t;
		ans += b * (15 + 16*5);
		ans += r * (15 + 16*3);
		ans += g * 7;
		ans += c * 2;
		ans += s * 3;
		cout << ans << endl;
	}
	return 0;
}
