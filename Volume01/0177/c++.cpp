#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double N1, E1, N2, E2;
	while(cin >> N1 >> E1 >> N2 >> E2, E1 != -1)
	{
		N1 *= M_PI/180;
		E1 *= M_PI/180;
		N2 *= M_PI/180;
		E2 *= M_PI/180;
		double X = acos(cos(E1)*cos(N1)*cos(E2)*cos(N2) + sin(E1)*cos(N1)*sin(E2)*cos(N2) + sin(N1)*sin(N2));
		cout << round(6378.1*min(X, 2*M_PI-X)) << endl;
	}
	return 0;
}