#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define EPS 1e-8
inline bool forward_vv(double x1, double y1, double x2, double y2){
	return x1*x2 + y1*y2 >= 0;
}

int main()
{
	double D;
	while(cin >> D, D != 0)
	{
		double px, py, vx, vy;
		cin >> px >> py >> vx >> vy;
		if(fabs(px * vy - py * vx) < EPS)
		{
			double d = sqrt(px*px+py*py);
			if(forward_vv(px, py, vx, vy))
				d = 2 - d;
			if(D - d >= EPS)
				printf("%.8f\n", d);
			else
				cout << "impossible" << endl;
		}
		else
			cout << "impossible" << endl;
	}
	return 0;
}
