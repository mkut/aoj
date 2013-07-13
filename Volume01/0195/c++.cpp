#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int sale[5];
	int am, pm;
	while(cin >> am >> pm, am+pm)
	{
		sale[0] = am+pm;
		for(int i = 1; i < 5; i++)
		{
			cin >> am >> pm;
			sale[i] = am+pm;
		}
		
		char name;
		int maxSale = 0;
		for(int i = 0; i < 5; i++)
		{
			if(maxSale < sale[i])
			{
				maxSale = sale[i];
				name = 'A' + i;
			}
		}
		cout << name << " " << maxSale << endl;
	}
	return 0;
}
