#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	string sx1, sy1, sx2, sy2, sxq, syq;
	while(getline(cin, sx1, ','))
	{
		getline(cin, sy1, ',');
		getline(cin, sx2, ',');
		getline(cin, sy2, ',');
		getline(cin, sxq, ',');
		getline(cin, syq);
		double x1, y1, x2, y2, xq, yq;
		x1 = atof(sx1.c_str());
		y1 = atof(sy1.c_str());
		x2 = atof(sx2.c_str());
		y2 = atof(sy2.c_str());
		xq = atof(sxq.c_str());
		yq = atof(syq.c_str());
		
		double naiseki = (x2-x1)*(xq-x1) + (y2-y1)*(yq-y1);
		double asix = x1 + (x2-x1) / ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) * naiseki;
		double asiy = y1 + (y2-y1) / ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) * naiseki;
		double xr = 2 * asix - xq;
		double yr = 2 * asiy - yq;
		
		printf("%.6f %.6f\n", xr, yr);
	}
	return 0;
}