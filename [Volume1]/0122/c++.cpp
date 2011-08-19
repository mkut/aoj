#include <iostream>
#include <list>
#include <map>
#include <stdlib.h>
using namespace std;

list<pair<int, int> > nextmove(list<pair<int, int> > movable, int x, int y)
{
	const int jump[12][2] = {{-2,-1},{-2,0},{-2,1},{-1,-2},{0,-2},{1,-2},{-1,2},{0,2},{1,2},{2,-1},{2,0},{2,1}};
	list<pair<int, int> > ret;
	for(list<pair<int, int> >::iterator it = movable.begin(); it != movable.end(); it++)
	{
		for(int i = 0; i < 12; i++)
		{
			if(abs(it->first + jump[i][0] - x) <= 1 && abs(it->second + jump[i][1] - y) <= 1
					&& it->first + jump[i][0] >= 0 && it->first + jump[i][0] <= 9
					&& it->second + jump[i][1] >= 0 && it->second + jump[i][1] <= 9)
			{
				ret.push_back(pair<int, int>(it->first + jump[i][0], it->second + jump[i][1]));
			}
		}
	}
	
	return ret;
}

int main()
{
	int x, y;
	while(cin >> x >>y, x != 0 || y != 0)
	{
		int n;
		int sprinx[10], spriny[10];
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> sprinx[i] >> spriny[i];
		}
		
		list<pair<int, int> > movable;
		movable.push_back(pair<int, int>(x, y));
		
		for(int i = 0; i < n; i++)
		{
			movable = nextmove(movable, sprinx[i], spriny[i]);
		}
		cout << (movable.size() > 0 ? "OK" : "NA") << endl;
	}
	return 0;
}