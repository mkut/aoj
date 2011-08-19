#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

double clock_h(int h, int m)
{
	return (double)360*(h+(double)m/60)/12;
}
double clock_m(int m)
{
	return (double)360*m/60;
}

double _abs(double d)
{
	return d > 0 ? d : -d;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string input;
		cin >> input;
		int h = atoi(input.substr(0,2).c_str());
		int m = atoi(input.substr(3,2).c_str());
		if(min(_abs(clock_h(h, m) - clock_m(m)), 360-_abs(clock_h(h, m) - clock_m(m))) < 30)
		{
			cout << "alert" << endl;
		}
		else if(min(_abs(clock_h(h, m) - clock_m(m)), 360-_abs(clock_h(h, m) - clock_m(m))) < 90)
		{
			cout << "warning" << endl;
		}
		else
		{
			cout << "safe" << endl;
		}
	}
	return 0;
}