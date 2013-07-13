#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	while(cin >> N >> M, N)
	{
		vector<int> _map(N), dice(M);
		for(int i = 0; i < N; i++)
			cin >> _map[i];
		for(int i = 0; i < M; i++)
			cin >> dice[i];
		
		int cur = 0;
		for(int i = 0; i <= M; i++)
		{
			if(cur >= N-1)
			{
				cout << i << endl;
				break;
			}
			cur += dice[i];
			cur += _map[cur];
		}
	}
	return 0;
}
