#include <iostream>
using namespace std;

int cnv(int y, int m, int d)
{
	const int day[] = {0,31,59,90,120,151,181,212,243,273,304,334};
	
	int ret = 0;
	
	ret += y*365 + (y+3)/4 - (y+99)/100 + (y+399)/400;
	ret += day[m-1] + (m>2 && y%4 == 0 && (y%100 != 0 || y%400 == 0) ? 1 : 0);
	ret += d-1;
	return ret;
}

int main()
{
	int y1, m1, d1, y2, m2, d2;
	
	while(cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2, y1 != -1)
	{
		cout << cnv(y2,m2,d2) - cnv(y1,m1,d1) << endl;
	}
	return 0;
}