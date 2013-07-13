#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char sx[4][100], sy[4][100];
	while(cin.getline(sx[0], 100, ','), cin.getline(sy[0], 100, ','))
	{
		for(int i = 1; i < 4; i++)
		{
			cin.getline(sx[i], 100, ',');
			if(i != 3)
			{
				cin.getline(sy[i], 100, ',');
			}
			else
			{
				cin.getline(sy[i], 100, '\n');
			}
		}
		
		double x[4], y[4];
		for(int i = 0; i < 4; i++)
		{
			x[i] = atof(sx[i]);
			y[i] = atof(sy[i]);
		}
		
		double vx[4], vy[4];
		vx[0] = x[0] - x[3];
		vy[0] = y[0] - y[3];
		for(int i = 1; i < 4; i++)
		{
			vx[i] = x[i] - x[i-1];
			vy[i] = y[i] - y[i-1];
		}
		
		bool dir[4];
		dir[0] = vx[0]*vy[3] - vx[3]*vy[0] > 0;
		for(int i = 1; i < 4; i++)
		{
			dir[i] = vx[i]*vy[i-1] - vx[i-1]*vy[i] > 0;
		}
		
		if(dir[0] == dir[1] && dir[0] == dir[2] && dir[0] == dir[3])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}