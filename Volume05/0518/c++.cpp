#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

bool check(const bitset<5001*5001>& _map, int x1, int y1, int x2, int y2)
{
	int pos[4];
	pos[0] = (x1 + y2 - y1)*5001 + y1 + x1 - x2;
	pos[1] = (x2 + y2 - y1)*5001 + y2 + x1 - x2;
	pos[2] = (x1 - y2 + y1)*5001 + y1 - x1 + x2;
	pos[3] = (x2 - y2 + y1)*5001 + y2 - x1 + x2;
	for(int i = 0; i < 4; i++)
	{
		if(pos[i] < 0 || pos[i] >= 5001*5001) return false;
	}
	return (_map[pos[0]] && _map[pos[1]]) || (_map[pos[2]] && _map[pos[3]]);
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		bitset<5001*5001> _map;
		vector<int> x(n), y(n);
		for(int i = 0; i < n; i++)
		{
			int tmpx, tmpy;
			cin >> tmpx >> tmpy;
			_map[tmpx*5001+tmpy] = true;
			x[i] = tmpx;
			y[i] = tmpy;
		}
		
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				if(check(_map, x[i], y[i], x[j], y[j]))
				{
					ans = max(ans, (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}