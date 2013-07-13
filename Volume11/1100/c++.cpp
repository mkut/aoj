#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int No = 0;
	int n;
	while(cin >> n, No++, n)
	{
		vector<int> x(n+1), y(n+1);
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		x[n] = x[0]; y[n] = y[0];
		
		double sum = 0;
		for(int i = 0; i < n; i++)
			sum += (x[i+1]+x[i])*(y[i+1]-y[i])/2.0;
		printf("%d %.1f\n", No, fabs(sum));
	}
	return 0;
}
