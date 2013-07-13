#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#include <sstream>
template<class T>
string expand(const string& sep, const T& val){
	ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
string expand(const string& sep, const vector<T>& vt){
//	assert(sep.length() > 0);
	
	string str = "";
	bool first = true;
	for(int i = 0; i < vt.size(); i++){
		if(!first){
			str += sep[0];
		}
		str += expand(sep.substr(1), vt[i]);
		first = false;
	}
	return str;
}

template<class T>
string operator+(const string& sep, const vector<T>& vt){
	return expand(sep, vt);
}

bool solve(vector<vector<int> >& maze, int x, int y, int xg, int yg, int c)
{
	if(maze[y][x] != c)
		return false;
	if(x == xg && y == yg)
		return true;
	
	maze[y][x] = 0;
	bool res = false;
	res |= solve(maze, x-1, y, xg, yg, c);
	res |= solve(maze, x+1, y, xg, yg, c);
	res |= solve(maze, x, y-1, xg, yg, c);
	res |= solve(maze, x, y+1, xg, yg, c);
	return res;
}

int main()
{
	int w, h;
	while(cin >> w >> h, w != 0)
	{
		vector<vector<int> > maze(h+2);
		for(int i = 0; i < h+2; i++)
			maze[i] = vector<int>(w+2);
		
		int xs, ys, xg, yg, n;
		cin >> xs >> ys >> xg >> yg >> n;
		
		for(int i = 0; i < n; i++)
		{
			int c, d, x, y;
			cin >> c >> d >> x >> y;
			const int dy[2][8] = {{0,1,0,1,0,1,0,1},{0,0,1,1,2,2,3,3}};
			const int dx[2][8] = {{0,0,1,1,2,2,3,3},{0,1,0,1,0,1,0,1}};
			for(int j = 0; j < 8; j++)
				maze[y+dy[d][j]][x+dx[d][j]] = c;
		}
		
		//cout << "\n "+maze << endl;
		
		if(maze[ys][xs] == 0)
			cout << "NG" << endl;
		else
			cout << (solve(maze, xs, ys, xg, yg, maze[ys][xs]) ? "OK" : "NG") << endl;
		//cout << "\n "+maze << endl;
	}
	return 0;
}
