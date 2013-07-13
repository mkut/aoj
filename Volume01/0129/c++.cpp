#include <iostream>
#include <math.h>
using namespace std;

bool distancechk(int x1, int y1, int x2, int y2, int cx, int cy, int cr)
{
	double _cos = ((x2-x1)*(cx-x1) + (y2-y1)*(cy-y1))/sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))/sqrt((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1));
	return sqrt((cx-x1)*(cx-x1) + (cy-y1)*(cy-y1))*sqrt(1-_cos*_cos)-0.0001 <= cr && _cos > 0;
}

bool inner(int x, int y, int cx, int cy, int cr)
{
	return (x-cx)*(x-cx) + (y-cy)*(y-cy) < cr *cr;
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int wallx[100], wally[100], wallr[100];
		for(int i = 0; i < n; i++)
		{
			cin >> wallx[i] >> wally[i] >> wallr[i];
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; i++)
		{
			int tx, ty, sx, sy;
			cin >> tx >> ty >> sx >> sy;
			bool finished = false;
			for(int j = 0; j < n; j++)
			{
				if(inner(tx, ty, wallx[j], wally[j], wallr[j]) != inner(sx, sy, wallx[j], wally[j], wallr[j]))
				{
					cout << "Safe" << endl;
					finished = true;
					break;
				}
				else if(distancechk(tx, ty, sx, sy, wallx[j], wally[j], wallr[j]) && !inner(tx, ty, wallx[j], wally[j], wallr[j]))
				{
					cout << "Safe" << endl;
					finished = true;
					break;
				}
			}
			if(!finished) cout << "Danger" << endl;
		}
	}
	return 0;
}