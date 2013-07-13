#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double x, h;
	while(cin >> x >> h, x != 0 || h != 0)
	{
		printf("%.6f\n", x * sqrt(x*x/4+h*h) * 2 + x*x);
	}
	return 0;
}