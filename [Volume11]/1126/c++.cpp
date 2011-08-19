#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string zerocut(string a)
{
	while(a.length() > 0 && a[0] == '0')
		a = a.substr(1);
	return a;
}

string _max(string a, string b)
{
	if(a.length() > b.length())
		return a;
	if(a.length() < b.length())
		return b;
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] > b[i])
			return a;
		if(a[i] < b[i])
			return b;
	}
	return a;
}

class solver
{
	vector<string> _map;
	vector<vector<string> > memo;
	int H, W;
	
public:
	solver(vector<string> _Map)
	{
		H = _Map.size();
		W = _Map[0].length();
		memo = vector<vector<string> >(H);
		for(int i = 0; i < H; i++)
			memo[i] = vector<string>(W);
		
		_map = _Map;
	}
	
	string solve()
	{
		string ans;
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
			{
				if(memo[i][j] == "")
					ans = _max(ans, zerocut(solve(i,j)));
			}
		return ans;
	}
	
	string solve(int x, int y)
	{
		if(x >= _map.size()) return "";
		if(y >= _map[x].length()) return "";
		if(_map[x][y] < '0' || _map[x][y] > '9') return "";
		
		if(memo[x][y] != "") return memo[x][y];
		
		string right = solve(x, y+1), bottom = solve(x+1, y);
		string ret = _map[x][y] + _max(right, bottom);
		memo[x][y] = ret;
		return ret;
	}
};

int main()
{
	int W, H;
	while(cin >> W >> H, W != 0)
	{
		vector<string> _map(H);
		for(int i = 0; i < H; i++)
			cin >> _map[i];
		
		solver prob(_map);
		cout << prob.solve() << endl;
	}
	return 0;
}
