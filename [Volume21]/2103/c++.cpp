#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		//input
		int H, W;
		cin >> H >> W;
		string map[22];
		map[0] = "######################";
		map[21] = "######################";
		for(int i = 1; i <= H; i++){ cin >> map[i]; map[i] = '#' + map[i] + '#'; }
		int N;
		string operation;
		cin >> N >> operation;
		
		//simulate
		int posx, posy;
		int dirx, diry;
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				if(map[i][j] == '^'){ posx = j; posy = i; dirx = 0; diry =-1; }
				if(map[i][j] == '>'){ posx = j; posy = i; dirx = 1; diry = 0; }
				if(map[i][j] == 'v'){ posx = j; posy = i; dirx = 0; diry = 1; }
				if(map[i][j] == '<'){ posx = j; posy = i; dirx =-1; diry = 0; }
			}
		}
		for(int i = 0; i < N; i++)
		{
			if(operation[i] == 'U')
			{
				dirx = 0; diry =-1;
				if(map[posy+diry][posx+dirx] == '.'){ map[posy][posx] = '.'; posx += dirx; posy += diry; }
				map[posy][posx] = '^';
			}
			if(operation[i] == 'D')
			{
				dirx = 0; diry =1;
				if(map[posy+diry][posx+dirx] == '.'){ map[posy][posx] = '.'; posx += dirx; posy += diry; }
				map[posy][posx] = 'v';
			}
			if(operation[i] == 'L')
			{
				dirx = -1; diry =0;
				if(map[posy+diry][posx+dirx] == '.'){ map[posy][posx] = '.'; posx += dirx; posy += diry; }
				map[posy][posx] = '<';
			}
			if(operation[i] == 'R')
			{
				dirx = 1; diry =0;
				if(map[posy+diry][posx+dirx] == '.'){ map[posy][posx] = '.'; posx += dirx; posy += diry; }
				map[posy][posx] = '>';
			}
			if(operation[i] == 'S')
			{
				int bulx = posx, buly = posy;
				for(; map[buly][bulx] != '#'; )
				{
					if(map[buly][bulx] == '*')
					{
						map[buly][bulx] = '.';
						break;
					}
					bulx += dirx;
					buly += diry;
				}
			}
		}
		
		//output
		for(int i = 1; i <= H; i++)
		{
			for(int j = 1; j <= W; j++)
			{
				cout << map[i][j];
			}
			cout << endl;
		}
		if(T != 0) cout << endl;
	}
	return 0;
}