#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N)
	{
		int ans = 0;
		for(int i = 2; i*(i+1)/2 <= N; i++)
			if((N-i*(i+1)/2) % i == 0)
				ans++;
		cout << ans << endl;
	}
	return 0;
}
