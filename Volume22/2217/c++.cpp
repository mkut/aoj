#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int draw(vector<vector<int> >& jx, vector<vector<int> >& jy, int i, int j, int cur)
{
	//cout << i << "," << j << endl;
	if(i == -cur) return 1;
	if(i < 0) return 0;
	int nexti = jy[i][j], nextj = jx[i][j];
	jx[i][j] = jy[i][j] = -cur;
	return draw(jx, jy, nexti, nextj, cur);
}

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<vector<int> > jx(N, vector<int>(N)), jy(N, vector<int>(N));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				cin >> jx[i][j] >> jy[i][j];
		
		int ans = 0;
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(jx[i][j] != -1)
					ans += draw(jx, jy, i, j, i*N+j+1);
		
		cout << ans << endl;
	}
	return 0;
}
