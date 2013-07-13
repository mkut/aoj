#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int len(vector<string>& view, int x, int y, int dx, int dy)
{
	int ret = 0;
	for(int X = x+dx, Y = y+dy; view[X][Y] == '*'; X += dx, Y += dy)
		view[X][Y] = ' ', ret++;
	return ret;
}

int area(vector<string>& view, int x, int y)
{
	view[x][y] = ' ';
	int top = len(view, x, y, 0, 1);
	int height;
	int bottom;
	
	if(view[x+1][y-1] == '*')
	{
		height = len(view, x, y, 1, -1);
		bottom = len(view, x+height, y-height, 0, 1);
	}
	else if(view[x+1][y] == '*')
	{
		height = len(view, x, y, 1, 0);
		bottom = len(view, x+height, y, 0, 1);
	}
	else
	{
		height = len(view, x, y, 1, 1);
		bottom = len(view, x+height, y+height, 0, 1);
	}
	len(view, x, y+top, 1, -1);
	len(view, x, y+top, 1, 0);
	len(view, x, y+top, 1, 1);
	top++; height++; bottom++;
	return (top+bottom)*height/2;
}

int main()
{
	int h;
	for(int No = 1; cin >> h, h; No++)
	{
		string LF; getline(cin, LF);
		if(No > 1) cout << "----------" << endl;
		
		vector<string> view(h+2);
		view[0] = view[h+1] = string(82, ' ');
		for(int i = 1; i <= h; i++)
		{
			getline(cin, view[i]);
			view[i] = " " + view[i] + string(81-view[i].length(), ' ');
		}
		
		map<int,int> count;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= 80; j++)
				if(view[i][j] == '*')
					count[area(view, i, j)]++;
		
		for(map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}
