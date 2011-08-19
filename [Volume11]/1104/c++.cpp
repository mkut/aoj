#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int w, h;
	while(cin >> w >> h, w)
	{
		string com;
		int x = 1, y = 1, dir = 0;
		int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
		while(cin >> com, com != "STOP")
		{
			if(com == "FORWARD")
			{
				int tmp; cin >> tmp;
				x += dx[dir] * tmp;
				y += dy[dir] * tmp;
			}
			else if(com == "BACKWARD")
			{
				int tmp; cin >> tmp;
				x -= dx[dir] * tmp;
				y -= dy[dir] * tmp;
			}
			else if(com == "RIGHT")
				dir = (dir+1)%4;
			else if(com == "LEFT")
				dir = (dir+3)%4;
			x = max(x, 1); x = min(x, w);
			y = max(y, 1); y = min(y, h);
		}
		cout << x << " " << y << endl;
	}
	return 0;
}
