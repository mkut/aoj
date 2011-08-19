#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int w, h;
	
	int dx[] = {0,0,-1,1};
	int dy[] = {-1,1,0,0};
	while(cin >> w >> h, w)
	{
		int maze[64][64] = {};
		for(int i = 0; i <= w*2; i++)
		{
			maze[0][i] = 1;
			maze[h*2][i] = 1;
		}
		for(int i = 0; i <= h*2; i++)
		{
			maze[i][0] = 1;
			maze[i][w*2] = 1;
		}
		
		for(int i = 1; i < h*2; i++)
			for(int j = 1+i%2; j < w*2; j+=2)
				cin >> maze[i][j];
		
		vector<int> prev;
		prev.push_back(1*64+1);
		for(int d = 2; prev.size(); d++)
		{
			vector<int> next;
			for(int i = 0; i < prev.size(); i++)
			{
				int x = prev[i]/64, y = prev[i]%64;
				for(int k = 0; k < 4; k++)
				{
					if(!maze[x+dx[k]][y+dy[k]] && !maze[x+dx[k]*2][y+dy[k]*2])
					{
						next.push_back((x+dx[k]*2)*64 + y+dy[k]*2);
						maze[x+dx[k]*2][y+dy[k]*2] = d;
					}
				}
			}
			prev = next;
		}
		/*
		for(int i = 0; i <= h*2; i++)
		{
			for(int j = 0; j <= w*2; j++)
			{
				if(i%2 && j%2) cout << maze[i][j];
				else cout << (maze[i][j] ? '#' : '.');
			}
			cout << endl;
		}
		cout << endl;
		*/
		cout << maze[h*2-1][w*2-1] << endl;
	}
	return 0;
}
