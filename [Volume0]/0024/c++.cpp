#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double v;
	while(cin >> v)
	{
		double y = v * v / 19.6; //4.9*(v/9.8)*(v/9.8);
		int n = ceil((y + 5.0)/5.0) + 0.5;
		cout << n << endl;
	}
	
	return 0;
}