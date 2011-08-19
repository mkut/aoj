#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	double ansx[1001] = {0,1}, ansy[1001] = {0,0};
	for(int i = 2; i <= 1000; i++)
	{
		double norm = sqrt(ansx[i-1]*ansx[i-1]+ansy[i-1]*ansy[i-1]);
		ansx[i] = ansx[i-1] - ansy[i-1] / norm;
		ansy[i] = ansy[i-1] + ansx[i-1] / norm;
	}
	while(cin >> n, n != -1)
	{
		printf("%.2f\n%.2f\n", ansx[n], ansy[n]);
	}
	return 0;
}