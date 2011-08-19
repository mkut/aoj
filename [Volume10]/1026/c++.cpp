#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	long long N;
	while(cin >> N, N)
	{
		long long mid = (long long)(ceil(sqrt(N/2)) + 0.5);
		long long ans = 0;
		for(long long i = 1; i < mid; i++)
			ans += (long long)(ceil((double)N/2/i - mid) + 0.5);
		ans += N/2 - mid;
		ans *= 2;
		ans += mid*mid;
		ans *= 2;
		ans += N*2;
		ans *= 4;
		cout << ans << endl;
	}
	return 0;
}
