#include <iostream>
using namespace std;

int main()
{
	int input[9];
	bool map[11][11] = {};
	for(int i = 0; i < 9; i++) cin >> input[i];
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(i % 2 == 0)
			{
				map[i+1][8-2*j] = input[i] % 10 == 1;
				input[i] /= 10;
			}
			else
			{
				map[i+1][9-2*j] = input[i] % 10 == 1;
				input[i] /= 10;
			}
		}
	}
	
	cout << "R";
	int x = 1;
	int y = 3;
	int dir = 1;
	int dx[7] = {-1, 0, 1, 0, -1, 0, 1};
	int dy[7] = {0, 1, 0, -1, 0, 1, 0};
	char dc[7] = {'U', 'R', 'D', 'L', 'U', 'R', 'D'};
	while(x != 1 || y != 1)
	{
		if(map[x + dx[dir-1]][y + dy[dir-1]])
		{
			cout << dc[dir-1];
			dir = dir - 1 == 0 ? 4 : dir - 1;
		}
		else if(map[x + dx[dir]][y + dy[dir]])
		{
			cout << dc[dir];
		}
		else if(map[x + dx[dir+1]][y + dy[dir+1]])
		{
			cout << dc[dir+1];
			dir = dir + 1 == 5 ? 1 : dir + 1;
		}
		else
		{
			cout << dc[dir+2];
			dir = dir + 2 >= 5 ? dir - 2 : dir + 2;
		}
		x += dx[dir] * 2;
		y += dy[dir] * 2;
	}
	cout << endl;
	
	return 0;
}