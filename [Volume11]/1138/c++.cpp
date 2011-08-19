#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int main()
{
	int n, m, p, a, b;
	while(cin >> n >> m >> p >> a >> b, n != 0)
	{
		vector<int> baken(n);
		for(int i = 0; i < n; i++)
			cin >> baken[i];
		
		int path[30][30] = {};
		for(int i = 0; i < p; i++)
		{
			int t1, t2, tp;
			cin >> t1 >> t2 >> tp;
			path[t1-1][t2-1] = tp;
			path[t2-1][t1-1] = tp;
		}
		
		double time[30][256];
		for(int i = 0; i < m; i++)
			for(int j = 0; j < (1<<n); j++)
				time[i][j] = 1e8;
		
		time[a-1][(1<<n)-1] = 0;
		vector<int> prevpos, prevstate;
		prevpos.push_back(a-1);
		prevstate.push_back((1<<n)-1);
		while(prevpos.size() != 0)
		{
			vector<int> nextpos, nextstate;
			for(int i = 0; i < prevpos.size(); i++)
			{
				for(int j = 0; j < m; j++)
				{
					if(path[prevpos[i]][j] != 0)
					{
						for(int k = 0; k < n; k++)
						{
							if((prevstate[i] >> k & 1))
							{
								if(time[j][prevstate[i] ^ (1<<k)] == 1e8)
								{
									time[j][prevstate[i] ^ (1<<k)] = time[prevpos[i]][prevstate[i]] + (double)path[prevpos[i]][j] / baken[k];
									nextpos.push_back(j);
									nextstate.push_back(prevstate[i] ^ (1<<k));
								}
								else if(time[j][prevstate[i] ^ (1<<k)] > time[prevpos[i]][prevstate[i]] + (double)path[prevpos[i]][j] / baken[k])
								{
									time[j][prevstate[i] ^ (1<<k)] = time[prevpos[i]][prevstate[i]] + (double)path[prevpos[i]][j] / baken[k];
								}
							}
						}
					}
				}
			}
			prevpos = nextpos;
			prevstate = nextstate;
		}
		
		double _min = 1e8;
		for(int i = 0; i < (1<<n); i++)
			_min = min(_min, time[b-1][i]);
		
		if(_min == 1e8)
			cout << "Impossible" << endl;
		else
			printf("%.3f\n", _min);
	}
	return 0;
}
