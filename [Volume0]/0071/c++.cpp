#include <iostream>
using namespace std;

void bomb(string* map, int x, int y)
{;
	if(x < 0 || x >= 8 || y < 0 || y >= 8) return;
	if(map[y][x] == '0') return;
	
	map[y][x] = '0';
	int chainx[] = {-3,-2,-1,1,2,3,0,0,0,0,0,0}, chainy[] = {0,0,0,0,0,0,-3,-2,-1,1,2,3};
	for(int i = 0; i < 12; i++)
	{
		bomb(map, x+chainx[i], y+chainy[i]);
	}
}

int main()
{
	int n;
	cin >> n;
	for(int set = 1; set <= n; set++)
	{
		string map[8];
		int x, y;
		for(int i = 0; i < 8; i++) cin >> map[i];
		cin >> x >> y;
		bomb(map, x-1, y-1);
		
		printf("Data %d:\n", set);
		for(int i = 0; i < 8; i++)
		{
			cout << map[i] << endl;
		}
	}
	return 0;
}