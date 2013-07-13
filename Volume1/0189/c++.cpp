#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int d[10][10];
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 10; j++)
				d[i][j] = i == j ? 0 : 100000000;
		
		int m = 1;
		for(int i = 0; i < n; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			d[a][b] = min(d[a][b], c);
			d[b][a] = min(d[b][a], c);
			m = max(m, a+1);
			m = max(m, b+1);
		}
		
		for(int k = 0; k < m; k++)
			for(int i = 0; i < m; i++)
				for(int j = 0; j < m; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		
		int sum = 100000000;
		int town = 0;
		for(int i = 0; i < m; i++)
		{
			int s = 0;
			for(int j = 0; j < m; j++)
				s += d[i][j];
			if(sum > s)
			{
				town = i;
				sum = s;
			}
		}
		cout << town << " " << sum << endl;
	}
	return 0;
}
