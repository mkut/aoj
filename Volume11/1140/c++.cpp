#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

inline int state(int g, int y, int x)
{
	return g * 900 + y * 30 + x;
}
inline int _g(int s)
{
	return s / 900;
}
inline int _y(int s)
{
	return s % 900 / 30;
}
inline int _x(int s)
{
	return s % 30;
}

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		vector<string> _map(h+2);
		_map[0] = "xxxxxxxxxxxxxxxxxxxxxx";
		_map[h+1] = "xxxxxxxxxxxxxxxxxxxxxx";
		for(int i = 1; i <= h; i++)
		{
			string tmp; cin >> tmp;
			_map[i] = "x" + tmp + "x";
		}
		
		int goalnum = 0;
		int startstate = 0;
		for(int i = 1; i <= h; i++)
			for(int j = 1; j <= w; j++)
				if(_map[i][j] == '*')
					_map[i][j] = '0' + goalnum++;
				else if(_map[i][j] == 'o')
				{
					startstate = state(0, i, j);
					_map[i][j] = '.';
				}
		startstate += state((1<<goalnum)-1, 0, 0);
		
		map<int,int> ans;
		ans[startstate] = 0;
		vector<int> prevstate;
		prevstate.push_back(startstate);
		bool finished = false;
		for(int i = 0; prevstate.size() != 0; i++)
		{
			//cout << i << endl;
			vector<int> nextstate;
			for(vector<int>::iterator it = prevstate.begin(); it != prevstate.end(); ++it)
			{
				//cout << _g(*it) << "," << _y(*it) << "," << _x(*it) << endl;
				if(_g(*it) == 0)
				{
					cout << i << endl;
					finished = true;
					break;
				}
				
				int dx[] = {0,0,1,-1};
				int dy[] = {1,-1,0,0};
				for(int j = 0; j < 4; j++)
				{
					char nexttile = _map[_y(*it)+dy[j]][_x(*it)+dx[j]];
					int dg = 0;
					if(nexttile >= '0' && nexttile <= '9' && (_g(*it) >> nexttile-'0' & 1))
						dg = -(1 << nexttile-'0');
					int n_state = *it + state(dg,dy[j],dx[j]);
					
					//cout << "N" << _g(n_state) << "," << _y(n_state) << "," << _x(n_state) << "," << nexttile << endl;
					if(nexttile != 'x' && ans.count(n_state) == 0)
					{
						ans[n_state] = i;
						nextstate.push_back(n_state);
					}
				}
			}
			prevstate = nextstate;
			if(finished)
				break;
		}
		if(!finished)
			cout << -1 << endl;
	}
	return 0;
}
