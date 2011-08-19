#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct score
{
	int num;
	char color;
	score(int Num, char Color) : num(Num), color(Color) {}
	
	score operator+(const score& a)
	{
		return score(num + a.num, (color == 'O' ? a.color : (a.color == 'O' ? color : (color == a.color ? color : 'X'))));
	}
};

score draw(vector<string>& field, int x, int y)
{
	const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
	
	if(field[x][y] != '.')
		return score(0, field[x][y]);
	field[x][y] = 'O';
	
	score ret(1, 'O');
	for(int i = 0; i < 4; i++)
	{
		ret = ret + draw(field, x+dx[i], y+dy[i]);
	}
	return ret;
}

int main()
{
	int w, h;
	
	while(cin >> w >> h, w)
	{
		vector<string> field(h+2);
		field[0] = field[h+1] = string(w+2, 'O');
		for(int i = 1; i <= h; i++)
		{
			string str; cin >> str;
			field[i] = "O" + str + "O";
		}
		
		int scoreB = 0, scoreW = 0;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
			{
				score tmp = draw(field, i, j);
				if(tmp.color == 'B') scoreB += tmp.num;
				else if(tmp.color == 'W') scoreW += tmp.num;
			}
		cout << scoreB << " " << scoreW << endl;
	}
	
	return 0;
}
