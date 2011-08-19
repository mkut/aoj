#include <iostream>
using namespace std;

double _abs(double d)
{
	return d > 0 ? d : -d;
}

int main()
{
	double q;
	while(cin >> q, q != -1)
	{
		double qn = q/2;
		for(; _abs(qn*qn*qn - q) >= q*1e-5; qn = qn - (qn*qn*qn-q)/(3*qn*qn)){}
		printf("%.6f\n", qn);
	}
	return 0;
}