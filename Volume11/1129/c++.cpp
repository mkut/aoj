#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n, r, c;
	int *change;
	while(true)
	{
		cin >> n >> r;
		if(n == 0 && r == 0)
		{
			break;
		}
		c = 0;
		change = (int *)malloc(sizeof(int) * 2 * r);
		for(int i=0; i<r; i++)
		{
			cin >> change[2*i] >> change[2*i+1];
		}
		for(int i=0; i<r; i++)
		{
			if(c < change[2*r-2*i-1])
			{
				c += change[2*r-2*i-2] - 1;
			}
			else if(c < change[2*r-2*i-2] + change[2*r-2*i-1] - 1)
			{
				c -= change[2*r-2*i-1];
			}
		}
		free(change);
		cout << n-c << endl;
	}
	return 0;
}