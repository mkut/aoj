#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t = 0;
	int N;
	while(cin >> N, N != 0)
	{
		int ans[10][10] = {};
		
		int count = 0;
		for(int s = 0; s <= (N-1)*2; s++)
		{
			for(int x = s % 2 == 0 ? max(0, s+1-N) : min(N-1, s); x >= max(0, s+1-N) && x <= min(N-1, s); x += s % 2 == 0 ? 1 : -1)
			{
				ans[s-x][x] = ++count;
			}
		}
		
		printf("Case %d:\n", ++t);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				printf("%3d", ans[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}