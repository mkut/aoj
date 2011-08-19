#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, a;
	while(cin >> n >> m >> a, n != 0)
	{
		int bo[1001][101] = {};
		for(int i = 0; i < m; i++)
		{
			int h, p, q;
			cin >> h >> p >> q;
			bo[h][p] = q;
			bo[h][q] = p;
		}
		for(int i = 1000; i >= 1; i--)
		{
			if(bo[i][a] != 0)
				a = bo[i][a];
		}
		cout << a << endl;
	}
	return 0;
}
