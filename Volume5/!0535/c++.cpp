#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

int draw(bitset<90*90> _map, int pos, int m, int n)
{
	cout << pos/90 << "," << pos%90 << endl;
	if(!_map[pos]) return 0;
	_map[pos] = false;
	
	int _max = 0;
	if(pos % 90 > 0)
		_max = max(_max, draw(_map, pos-1, m, n) + 1);
	if(pos % 90 < m)
		_max = max(_max, draw(_map, pos+1, m, n) + 1);
	if(pos / 90 > 0)
		_max = max(_max, draw(_map, pos-90, m, n) + 1);
	if(pos / 90 < n)
		_max = max(_max, draw(_map, pos+90, m, n) + 1);
	return _max;
}

int main()
{
	int x[10];
	int m, n;
	while(cin >> m >> n, m != 0 || n != 0)
	{
		bitset<90*90> _map;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				int tmp; cin >> tmp;
				if(tmp == 1)
					_map[i*90+j] = true;
				else
					_map[i*90+j] = false;
			}
		int _max = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				_max = max(_max, draw(_map, i*90+j, m, n));
		
		cout << _max << endl;
	}
	return 0;
}
