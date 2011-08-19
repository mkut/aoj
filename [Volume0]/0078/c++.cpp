#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int map[15][15] = {};
		
		int posx = n/2+1, posy = n/2;
		for(int i = 1; i <= n*n; i++)
		{
			if(posx < 0) posx += n;
			if(posx >= n) posx -= n;
			if(posy < 0) posy += n;
			if(posy >= n) posy -= n;
			
			if(map[posx][posy] == 0)
			{
				map[posx][posy] = i;
				posx++;
				posy++;
			}
			else
			{
				posx++;
				posy--;
				i--;
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				printf("%4d", map[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}