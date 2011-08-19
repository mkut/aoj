#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template<class T>
string operator+(const string& sep, const vector<T>& vt){
	return expand(sep, vt);
}

int solve(int remain, vector<string> _map, int y, int x)
{
	if(remain == 0) return 100;
	int r = 100;
	int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
	for(int i = 0; i < 4; i++)
	{
		int curx = x, cury = y;
		while(_map[cury+dy[i]][curx+dx[i]] == '.')
		{
			cury += dy[i];
			curx += dx[i];
		}
		if(_map[cury+dy[i]][curx+dx[i]] == 'g')
			return 1;
		if(_map[cury+dy[i]][curx+dx[i]] == '#' && (cury != y || curx != x))
		{
			_map[cury+dy[i]][curx+dx[i]] = '.';
			r = min(r, solve(remain-1, _map, cury, curx) + 1);
			_map[cury+dy[i]][curx+dx[i]] = '#';
		}
	}
	return r;
}

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		int y, x;
		vector<string> _map(h+2);
		_map[0] = "xxxxxxxxxxxxxxxxxxxxxx";
		_map[h+1] = "xxxxxxxxxxxxxxxxxxxxxx";
		for(int i = 1; i <= h; i++)
		{
			_map[i] = "x";
			for(int j = 1; j <= w; j++)
			{
				int tmp; cin >> tmp;
				_map[i] += tmp == 1 ? "#" : (tmp == 3 ? "g" : ".");
				if(tmp == 2)
				{
					y = i; x = j;
				}
			}
			_map[i] += "x";
		}
		
		int ans = solve(10, _map, y, x);
		cout << (ans >= 100 ? -1 : ans) << endl;
	}
	return 0;
}
