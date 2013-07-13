#include <iostream>
#include <vector>
using namespace std;

int draw(int y, int x, vector<string>& tiles)
{
	if(tiles[y][x] == '#') return 0;
	tiles[y][x] = '#';
	int r = 1;
	r += draw(y+1, x, tiles);
	r += draw(y-1, x, tiles);
	r += draw(y, x+1, tiles);
	r += draw(y, x-1, tiles);
	return r;
}

int main()
{
	int W, H;
	while(cin >> W >> H, W != 0 || H != 0)
	{
		vector<string> tiles;
		tiles.push_back("######################");
		for(int i = 0; i < H; i++)
		{
			string tmp; cin >> tmp;
			tiles.push_back('#' + tmp + '#');
		}
		tiles.push_back("######################");
		
		int y, x;
		for(int i = 0; i < H+2; i++)
		{
			for(int j = 0; j < W+2; j++)
			{
				if(tiles[i][j] == '@')
				{
					y = i;
					x = j;
				}
			}
		}
		
		cout << draw(y, x, tiles) << endl;
	}
	return 0;
}