#include <iostream>
using namespace std;

int main()
{
	int map[30][30] = {};
	string input;
	while(cin >> input)
	{
		int x = input[0] - '0' + 10;
		int y = input[2] - '0' + 10;
		int size = input[4] - '0';
		
		map[x][y]++;
		map[x-1][y]++;
		map[x+1][y]++;
		map[x][y-1]++;
		map[x][y+1]++;
		if(size >= 2)
		{
			map[x-1][y-1]++;
			map[x+1][y-1]++;
			map[x-1][y+1]++;
			map[x+1][y+1]++;
		}
		if(size >= 3)
		{
			map[x][y-2]++;
			map[x][y+2]++;
			map[x-2][y]++;
			map[x+2][y]++;
		}
	}
	
	int white = 0;
	int max = 0;
	for(int i = 10; i < 20; i++)
	{
		for(int j = 10; j < 20; j++)
		{
			if(map[i][j] == 0) white++;
			max = map[i][j] > max ? map[i][j] : max;
		}
	}
	
	cout << white << endl << max << endl;
	
	return 0;
}