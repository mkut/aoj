#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <set>

int dxs[] = {1,-1,0,0}, dys[] = {0,0,1,-1};

int hash(int x, int y, int dx, int dy, int memory)
{
	return x + y * 100 + (dx+1) * 10000 + (dy+1) * 100000 + memory * 1000000;
}

class solver
{
	set<int> done;
	int R, C;
	vector<string> code;
public:
	solver(int R, int C, vector<string>& code) : R(R), C(C), code(code) {}
	
	int go() { return go(0, 0, 0, 1, 0); }
	int go(int x, int y, int dx, int dy, int memory)
	{
		if(x < 0) x += R;
		if(x >= R) x -= R;
		if(y < 0) y += C;
		if(y >= C) y -= C;
		int h = hash(x, y, dx, dy, memory);
		//cout << x << "," << y << "," << dx << "," << dy << "," << memory << endl;
		if(done.count(h))
			return 0;
		done.insert(h);

		int ret = 0;
		switch(code[x][y])
		{
		case '<':
			dx = 0; dy = -1;
			return go(x+dx, y+dy, dx, dy, memory);
		case '>':
			dx = 0; dy = 1;
			return go(x+dx, y+dy, dx, dy, memory);
		case '^':
			dx = -1; dy = 0;
			return go(x+dx, y+dy, dx, dy, memory);
		case 'v':
			dx = 1; dy = 0;
			return go(x+dx, y+dy, dx, dy, memory);
		case '_':
			dx = 0; dy = memory == 0 ? 1 : -1;
			return go(x+dx, y+dy, dx, dy, memory);
		case '|':
			dx = memory == 0 ? 1 : -1; dy = 0;
			return go(x+dx, y+dy, dx, dy, memory);
		case '?':
			for(int i = 0; i < 4; i++)
			{
				dx = dxs[i]; dy = dys[i];
				ret |= go(x+dx, y+dy, dx, dy, memory);
			}
			return ret;
		case '.':
			return go(x+dx, y+dy, dx, dy, memory);
		case '@':
			return 1;
		case '+':
			return go(x+dx, y+dy, dx, dy, (memory+1)%16);
		case '-':
			return go(x+dx, y+dy, dx, dy, (memory+15)%16);
		default:
			return go(x+dx, y+dy, dx, dy, code[x][y]-'0');
		}
	}
};

int main()
{
	int R, C; cin >> R >> C;
	vector<string> code(R);
	for(int i = 0; i < R; i++)
		cin >> code[i];
	solver prob(R, C, code);
	cout << (prob.go() ? "YES" : "NO") << endl;
	return 0;
}
