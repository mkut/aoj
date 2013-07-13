#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int W;
	for(int no = 1; cin >> W, W != 0; no++)
	{
		int N = 0;
		string svalue[1001], sweight[1001];
		int value[1001], weight[1001];
		int maxval[1001][1001] = {};
		
		cin >> N;
		
		getline(cin, svalue[0], '\n');
		for(int i = 1; i <= N; i++)
		{
			getline(cin, svalue[i], ',');
			getline(cin, sweight[i], '\n');
		}
		for(int i = 1; i <= N; i++)
		{
			value[i] = atoi(svalue[i].c_str());
			weight[i] = atoi(sweight[i].c_str());
		}
		
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				int yes = j-weight[i] < 0 ? 0 : maxval[i-1][j-weight[i]] + value[i];
				maxval[i][j] = yes > maxval[i-1][j] ? yes : maxval[i-1][j];
			}
		}
		int minwei = 0;
		for(; maxval[N][minwei] != maxval[N][W]; minwei++){}
		
		printf("Case %d:\n%d\n%d\n", no, maxval[N][W], minwei);
	}
	return 0;
}