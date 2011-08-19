#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int gx, gy;
		cin >> gx >> gy;
		int p;
		cin >> p;
		bool ngyoko[16][16] = {};
		bool ngtate[16][16] = {};
		for(int i = 0; i < p; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if(x1 == x2)
				ngtate[x1][max(y1,y2)] = true;
			else
				ngyoko[max(x1,x2)][y1] = true;
		}
		
		int ans[16][16] = {};
		ans[0][0] = 1;
		for(int i = 0; i <= gx; i++)
		{
			for(int j = 0; j <= gy; j++)
			{
				if(i != 0 && !ngyoko[i][j])
					ans[i][j] += ans[i-1][j];
				if(j != 0 && !ngtate[i][j])
					ans[i][j] += ans[i][j-1];
			}
		}
		if(ans[gx][gy] == 0)
			cout << "Miserable Hokusai!" << endl;
		else
			cout << ans[gx][gy] << endl;
	}
	return 0;
}
