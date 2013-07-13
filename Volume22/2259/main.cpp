#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int M, N; cin >> M >> N;
	int ans = 0;
	for(int i = 0; i < M; i++)
	{
		int solved = 0;
		for(int j = 0; j < N; j++)
		{
			int tmp; cin >> tmp;
			solved += tmp;
		}
		ans = max(ans, solved);
	}
	cout << ans << endl;
	return 0;
}
