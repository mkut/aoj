#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int,int> Point;
typedef pair<Point,bool> State;

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		vector<State> prev;
		map<State,int> ans;
		vector<string> _map(h);
		for(int i = 0; i < h; i++)
			for(int j = 0; j < w; j++)
			{
				char tmp; cin >> tmp;
				if(tmp == 'S')
				{
					prev.push_back(State(Point(i, j), true));
					prev.push_back(State(Point(i, j), false));
					ans[State(Point(i, j), true)] = 0;
					ans[State(Point(i, j), false)] = 0;
				}
				_map[i] += tmp;
			}
		
		int _min = 1000000;
		while(prev.size() != 0)
		{
			vector<State> next;
			for(vector<State>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				const int di[] = {2,1,1,0,0,0,-1,-1,-2};
				const int dj[] = {1,1,2,1,2,3,1,2,1};
				for(int k = 0; k < 9; k++)
				{
					int next_i = it->first.first + di[k];
					int next_j = it->first.second + dj[k] * (it->second ? 1 : -1);
					bool next_LR = !it->second;
					if(next_i >= 0 && next_i < h && next_j >= 0 && next_j < w)
					{
						char next_tile = _map[next_i][next_j];
						if(next_tile == 'T')
						{
							_min = min(_min, ans[*it]);
							continue;
						}
						State next_state = State(Point(next_i, next_j), next_LR);
						if(next_tile != 'X' && next_tile != 'S' && (ans.count(next_state) == 0 || ans[next_state] > ans[*it] + next_tile - '0'))
						{
							next.push_back(next_state);
							ans[next_state] = ans[*it] + next_tile - '0';
						}
					}
				}
			}
			prev = next;
		}
		cout << (_min == 1000000 ? -1 : _min) << endl;
	}
	return 0;
}
