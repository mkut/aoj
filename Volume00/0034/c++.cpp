#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	char sl[10][100], sv[2][100];
	int l[10], v[2];
	while(cin.getline(sl[0], 100, ','))
	{
		for(int i = 1; i < 10; i++)
		{
			cin.getline(sl[i], 100, ',');
		}
		cin.getline(sv[0], 100, ',');
		cin.getline(sv[1], 100, '\n');
		
		for(int i = 0; i < 10; i++) l[i] = atoi(sl[i]);
		for(int i = 0; i < 2; i++) v[i] = atoi(sv[i]);
		
		int total = 0;
		for(int i = 0; i < 10; i++) total += l[i];
		
		double crash = (double)total * v[0] / (v[0] + v[1]);
		
		total = 0;
		for(int i = 0; i < 10; i++)
		{
			total += l[i];
			if(total >= crash)
			{
				cout << i+1 <<endl;
				break;
			}
		}
	}
	return 0;
}