#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, m;
	while(cin >> n >> k >> m, n)
	{
		int prev = 0;
		for(int i = 1; i < n; i++)
			prev = (k + prev - 1) % i + 1;
		cout << (prev + m - 1) % n + 1 << endl;
	}
	return 0;
}
