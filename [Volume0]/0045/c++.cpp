#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
	unsigned long long sum = 0, sumamount = 0, num = 0;
	string svalue, samount;
	while(getline(cin, svalue, ','))
	{
		getline(cin, samount, '\n');
		int value = atoi(svalue.c_str());
		int amount = atoi(samount.c_str());
		sum += value * amount;
		sumamount += amount;
		num++;
	}
	cout << sum << endl << round((double)sumamount/num) << endl;
	return 0;
}