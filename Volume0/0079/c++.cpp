#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

double heron(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	double b = sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));
	double c = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
	double z = (a+b+c)/2;
	return sqrt(z*(z-a)*(z-b)*(z-c));
}

int main()
{
	string sp0x, sp0y, sp1x, sp1y;
	double p0x, p0y, p1x, p1y;
	getline(cin, sp0x, ',');
	getline(cin, sp0y);
	getline(cin, sp1x, ',');
	getline(cin, sp1y);
	p0x = atof(sp0x.c_str());
	p0y = atof(sp0y.c_str());
	p1x = atof(sp1x.c_str());
	p1y = atof(sp1y.c_str());
	
	string spx, spy;
	double px, py;
	double sum = 0;
	while(getline(cin, spx, ','), getline(cin, spy))
	{
		px = atof(spx.c_str());
		py = atof(spy.c_str());
		sum += heron(p0x, p0y, p1x, p1y, px, py);
		p1x = px;
		p1y = py;
	}
	printf("%.6f\n", sum);
	return 0;
}