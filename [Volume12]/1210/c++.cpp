#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		int dice[3] = {1,5,4};
		for(int i = 0; i < n; i++)
		{
			string str; cin >> str;
			switch(str[0])
			{
				case 'n':
					swap(dice[0], dice[1]);
					dice[1] = 7 - dice[1];
					break;
				case 's':
					swap(dice[0], dice[1]);
					dice[0] = 7 - dice[0];
					break;
				case 'w':
					swap(dice[0], dice[2]);
					dice[2] = 7 - dice[2];
					break;
				case 'e':
					swap(dice[0], dice[2]);
					dice[0] = 7 - dice[0];
					break;
			}
		}
		cout << dice[0] << endl;
	}
	return 0;
}
