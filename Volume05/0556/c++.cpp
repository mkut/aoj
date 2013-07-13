#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, K; cin >> N >> K;
	while(K--)
	{
		int x, y; cin >> x >> y;
		x = min(x, N + 1 - x);
		y = min(y, N + 1 - y);
		cout << (min(x, y) - 1) % 3 + 1 << endl;
	}
	return 0;
}
