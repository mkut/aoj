#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

struct State
{
	int py, px, gy, gx, p;
	State(int _py, int _px, int _gy, int _gx, int _p)
	{
		py = _py;
		px = _px;
		gy = _gy;
		gx = _gx;
		p = _p;
	}
};

class solver
{
	vector<string> _map;
	int H, W;
	string pattern;
	int ans[20][20][20][20][10];
	vector<State> cur;
	vector<State> next;
	
	int movey[5], movex[5];
	map<char,int> gmovey, gmovex;
	
  public:
	solver(vector<string> __map, string _pattern)
	{
		_map = __map;
		H = __map.size();
		W = __map[0].length();
		pattern = _pattern;
		memset(ans, -1, sizeof(ans));
		
		movey[0] = 0; movey[1] = 1; movey[2] =-1; movey[3] = 0; movey[4] = 0;
		movex[0] = 0; movex[1] = 0; movex[2] = 0; movex[3] = 1; movex[4] =-1;
		gmovey['2'] = 1; gmovey['4'] = 0; gmovey['5'] = 0; gmovey['6'] = 0; gmovey['8'] =-1;
		gmovex['2'] = 0; gmovex['4'] =-1; gmovex['5'] = 0; gmovex['6'] = 1; gmovex['8'] = 0;
	}
	
	void solve()
	{
		int py, px, gy, gx;
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if(_map[i][j] == 'A') {py = i; px = j;}
				if(_map[i][j] == 'B') {gy = i; gx = j;}
			}
		}
		State initial(py, px, gy, gx, 0);
		cur.push_back(initial);
		for(int i = 0; cur.size() > 0; i++)
		{
			for(int j = 0; j < cur.size(); j++)
			{
				//d(cur[j]);
				if(_solve(cur[j]))
				{
					printf("%d %d %d\n", i, cur[j].py, cur[j].px);
					return;
				}
				
				ans[cur[j].py][cur[j].px][cur[j].gy][cur[j].gx][cur[j].p] = i;
			}
			cur = next;
			next = vector<State>();
		}
		printf("impossible\n");
	}
	
	bool _solve(State s)
	{
		//printf("%d,%d,%d,%d,%d", s.py, s.px, s.gy, s.gx, s.p);cout <<endl;
		if(ans[s.py][s.px][s.gy][s.gx][s.p] != -1) return false;
		if(_map[s.py][s.px] == '#') return false;
		if(s.py == s.gy && s.px == s.gx) return true;
		
		for(int i = 0; i < 5; i++)
		{
			int next_py, next_px, next_gy, next_gx, next_p;
			next_py = s.py+movey[i];
			next_px = s.px+movex[i];
			if(next_py < 0 || next_py >= H || next_px < 0 || next_px >= W) continue;
			next_gy = s.gy+gmovey[pattern[s.p]];
			if(next_gy < 0) next_gy = 0;
			else if(next_gy >= H) next_gy = H-1;
			next_gx = s.gx+gmovex[pattern[s.p]];
			if(next_gx < 0) next_gx = 0;
			else if(next_gx >= W) next_gx = W-1;
			next_p = s.p==pattern.size()-1 ? 0 : s.p+1;
			next.push_back(State(next_py, next_px, next_gy, next_gx, next_p));
			
		}
		return false;
	}
	
	void d(State s)
	{
		for(int i = 0; i < pattern.length(); i++)
		{
			if(i == s.p) cout << '(' << pattern[i] << ')';
			else cout << pattern[i];
		}
		cout << endl;
		for(int i = 0; i < H; i++)
		{
			for(int j = 0; j < W; j++)
			{
				if(i == s.py && j == s.px) cout << 'A';
				else if(i == s.gy && j == s.gx) cout << 'B';
				else if(_map[i][j] == 'A' || _map[i][j] == 'B') cout << '.';
				else cout << _map[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main()
{
	int H, W;
	while(cin >> H >> W, H != 0 || W != 0)
	{
		vector<string> _map(H);
		string pattern;
		for(int i = 0; i < H; i++)
		{
			cin >> _map[i];
		}
		cin >> pattern;
		solver prob(_map, pattern);
		prob.solve();
	}
	return 0;
}