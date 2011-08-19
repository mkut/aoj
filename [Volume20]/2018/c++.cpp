#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, P;
	while(cin >> N >> M >> P, N)
	{
		int sum = 0, hit;
		for(int i = 1; i <= N; i++)
		{
			int tmp; cin >> tmp;
			sum += tmp;
			if(i == M)
				hit = tmp;
		}
		
		if(hit == 0)
			cout << 0 << endl;
		else
			cout << sum * (100-P) / hit << endl;
	}
	return 0;
}
