#include <iostream>
using namespace std;

int main()
{
	int m, d;
	int day[14] = {0, 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string week[7] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
	for(int i = 1; i < 14; i++)
	{
		day[i] += day[i-1];
	}
	while(cin >> m >> d, m != 0)
	{
		cout << week[(day[m]+d) % 7] << endl;
	}
	return 0;
}