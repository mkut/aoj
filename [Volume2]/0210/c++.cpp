#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void d(vector<string>& maze)
{
	for(int i = 0; i < maze.size(); i++)
		cout << maze[i] << endl;
	cout << endl;
}

int main()
{
	int dh[] = {0,1,0,-1}, dw[] = {-1,0,1,0};
	char cdir[] = {'W', 'S', 'E', 'N'};
	map<char,int> ndir; ndir['W'] = 0; ndir['S'] = 1; ndir['E'] = 2; ndir['N'] = 3;
	int W, H;
	while(cin >> W >> H, W)
	{
		vector<string> maze(H);
		for(int i = 0; i < H; i++)
			cin >> maze[i];
		
		bool exist;
		int count = 0;
		for(; count <= 180; count++)
		{
			//d(maze);
			exist = false;
			for(int i = 0; i < H; i++)
			{
				for(int j = 0; j < W; j++)
				{
					if(maze[i][j] == '.' || maze[i][j] == 'X' || maze[i][j] == '#')
						continue;
					exist = true;
					int L = ndir[maze[i][j]];
					for(int k = 3; k <= 7; k++)
					{
						if(k == 7)
						{
							maze[i][j] -= 'A' - 'a';
							break;
						}
						if(maze[i+dh[(L+k)%4]][j+dw[(L+k)%4]] == '.' || maze[i+dh[(L+k)%4]][j+dw[(L+k)%4]] == 'X')
						{
							maze[i][j] = cdir[(L+k)%4];
							break;
						}
					}
				}
			}
			
			if(!exist)
				break;
			
			for(int k = 0; k < 4; k++)
			{
				for(int i = 0; i < H; i++)
				{
					for(int j = 0; j < W; j++)
					{
						if(maze[i][j] == cdir[k])
						{
							if(maze[i+dh[k]][j+dw[k]] == '.')
							{
								maze[i+dh[k]][j+dw[k]] = maze[i][j] - 'A' + 'a';
								maze[i][j] = '.';
							}
							else if(maze[i+dh[k]][j+dw[k]] == 'X')
							{
								maze[i+dh[k]][j+dw[k]] = 'x';
								maze[i][j] = '.';
							}
						}
					}
				}
			}
			for(int i = 0; i < H; i++)
				for(int j = 0; j < W; j++)
					if(maze[i][j] >= 'a' && maze[i][j] <= 'z')
						maze[i][j] += 'A' - 'a';
		}
		
		if(count > 180)
			cout << "NA" << endl;
		else
			cout << count << endl;
	}
	return 0;
}
