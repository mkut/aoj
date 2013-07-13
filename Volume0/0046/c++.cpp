#include <iostream>
using namespace std;

int main()
{
	double max, min;
	cin >> max;
	min = max;
	double cur;
	while(cin >> cur)
	{
		max = cur > max ? cur : max;
		min = cur < min ? cur : min;
	}
	cout << max-min << endl;
	return 0;
}