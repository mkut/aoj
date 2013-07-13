#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		bool gem[21][21] = {};
		for(int i = 0; i < n; i++)
		{
			int x, y; cin >> x >> y;
			gem[x][y] = true;
		}
		
		int m;
		cin >> m;
		
		int px = 10, py = 10;
		if(gem[px][py])
		{
			gem[px][py] = false;
			n--;
		}
		map<char,int> dx, dy;
		dx['N'] = 0; dx['S'] = 0; dx['E'] = 1; dx['W'] =-1;
		dy['N'] = 1; dy['S'] =-1; dy['E'] = 0; dy['W'] = 0;
		for(int i = 0; i < m; i++)
		{
			char c;
			int x;
			cin >> c >> x;
			for(int j = 0; j < x; j++)
			{
				px += dx[c];
				py += dy[c];
				if(gem[px][py])
				{
					gem[px][py] = false;
					n--;
				}
			}
		}
		if(n == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}
