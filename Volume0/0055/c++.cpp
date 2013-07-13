#include <iostream>
using namespace std;

int main()
{
	double a;
	while(cin >> a)
	{
		double sum = a;
		a *= 2;
		sum += a;
		for(int i = 0; i < 4; i++)
		{
			a /= 3;
			sum += a;
			a *= 2;
			sum += a;
		}
		
		printf("%.8f\n", sum);
	}
	return 0;
}