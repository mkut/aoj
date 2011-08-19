#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	while(cin >> n >> k, n != 0)
	{
		vector<vector<int> > cost(n);
		for(int i = 0; i < n; i++)
		{
			cost[i] = vector<int>(n);
			for(int j = 0; j < n; j++)
				cost[i][j] = 1000000000;
		}
		while(k--)
		{
			int flag; cin >> flag;
			if(flag == 1)
			{
				int a, b, c;
				cin >> a >> b >> c;
				cost[a-1][b-1] = c;
				cost[b-1][a-1] = c;
				for(int i = 0; i < n; i++)
				{
					for(int j = 0; j < n; j++)
					{
						cost[i][j] = min(cost[i][j], cost[i][j]
					}
				}
			}
			else
			{
				int a, b;
				cin >> a >> b;
				cout << (cos[a-1][b-1] == 1000000000 ? -1 : cos[a-1][b-1]) << endl;
			}
		}
	}
	return 0;
}