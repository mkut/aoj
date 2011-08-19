#include <iostream>
using namespace std;

bool draw(bool* map, int x, int y)
{
	if(!map[x*14+y]) return false;
	
	map[x*14+y] = false;
	draw(map, x-1, y);
	draw(map, x+1, y);
	draw(map, x, y-1);
	draw(map, x, y+1);
	return true;
}

int main()
{
	string input;
	while(cin >> input)
	{
		bool map[14][14] = {};
		for(int i = 1; i <= 12; i++)
		{
			map[1][i] = input[i-1] == '1' ? true : false;
		}
		for(int i = 2; i <= 12; i++)
		{
			cin >> input;
			for(int j = 1; j <= 12; j++)
			{
				map[i][j] = input[j-1] == '1' ? true : false;
			}
		}
		
		int count = 0;
		for(int i = 1; i <= 12; i++)
		{
			for(int j = 1; j <= 12; j++)
			{
				count += draw(map[0], i, j) ? 1 : 0;
			}
		}
		
		cout << count << endl;
	}
	return 0;
}