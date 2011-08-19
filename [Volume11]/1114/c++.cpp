#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int m; cin >> m;
	while(m--)
	{
		int p[5][5];
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				cin >> p[i][j];
		
		int memo[6][6] = {};
		for(int i = 0; i < 5; i++)
		{
			int count = 0;
			for(int j = 0; j < 5; j++)
			{
				if(p[i][j]) count++;
				else count = 0;
				memo[i][j] = count;
			}
		}
		int ans = 0;
		for(int j = 0; j < 5; j++)
		{
			stack<int> counts; counts.push(0);
			stack<int> poss; poss.push(0);
			for(int i = 0; i < 6; i++)
			{
				int begin = i;
				while(counts.top() > memo[i][j])
				{
					begin = poss.top();
					ans = max(ans, counts.top() * (i-poss.top()));
					counts.pop(); poss.pop();
				}
				if(counts.top() < memo[i][j]) counts.push(memo[i][j]), poss.push(begin);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
