#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n >= 0)
	{
		vector<string> view(17, string(17, ' '));
		while(n--)
		{
			char xy; int X, Y; cin >> xy >> X >> Y;
			view[Y*2+(xy=='y'?1:0)][X*2+(xy=='x'?1:0)] = xy;
		}
		
		int x = 1, y = 2, dx = 1, dy = 1;
		while(true)
		{
			if(view[x][y] == 'x')
				dx *= -1;
			else if(view[x][y] == 'y')
				dy *= -1;
			x += dx;
			y += dy;
			if(x == 1 && y == 2 && dx == 1 && dy == 1)
			{
				x = 1;
				y = 3;
				break;
			}
			if(x < 0 || x > 16 || y < 0 || y > 16)
			{
				x = (x - dx) * 2;
				y = (y - dy) * 2;
				break;
			}
		}
		cout << y*25 << " " << x*25 << endl;
	}
	return 0;
}
