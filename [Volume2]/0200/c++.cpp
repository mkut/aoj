#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<vector<int> > time(m), fare(m);
		for(int i = 0; i < m; i++)
		{
			time[i] = vector<int>(m);
			fare[i] = vector<int>(m);
			for(int j = 0; j < m; j++)
			{
				time[i][j] = i == j ? 0 : 100000000;
				fare[i][j] = i == j ? 0 : 100000000;
			}
		}
		for(int i = 0; i < n; i++)
		{
			int a, b, c, t;
			cin >> a >> b >> c >> t;
			time[a-1][b-1] = t;
			time[b-1][a-1] = t;
			fare[a-1][b-1] = c;
			fare[b-1][a-1] = c;
		}
		for(int k = 0; k < m; k++)
			for(int i = 0; i < m; i++)
				for(int j = 0; j < m; j++)
				{
					time[i][j] = min(time[i][j], time[i][k] + time[k][j]);
					fare[i][j] = min(fare[i][j], fare[i][k] + fare[k][j]);
				}
		
		int K;
		cin >> K;
		for(int i = 0; i < K; i++)
		{
			int p, q, r;
			cin >> p >> q >> r;
			cout << (r == 0 ? fare[p-1][q-1] : time[p-1][q-1]) << endl;
		}
	}
	return 0;
}
