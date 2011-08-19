#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000;

class solver
{
	map<vector<char>, int> memo;
	vector<vector<int> > linked;
	int x;
public:
	solver(vector<vector<int> >& linked) : linked(linked), x(linked.size()) {}

	int solve(int cur, vector<char>& done)
	{
		if(cur == x) return 0;
		if(done[cur]) return solve(cur+1, done);
		
		int ret= INF;
		for(int i = 0; i < linked[cur].size(); i++)
		{
			int dom = linked[cur][i];
			vector<char> next_done = done;
			for(int j = 0; j < linked[dom].size(); j++)
				next_done[linked[dom][j]] = true;
			ret = min(ret, solve(cur+1, next_done) + 1);
		}
		return ret;
	}
	int solve()
	{
		vector<char> done(x);
		return solve(0, done);
	}
};

int main()
{
	int x, y;
	
	while(cin >> x >> y, x)
	{
		vector<vector<int> > linked(x);
		for(int i = 0; i < y; i++)
		{
			int a, b; cin >> a >> b;
			linked[a].push_back(b);
			linked[b].push_back(a);
		}
		for(int i = 0; i < x; i++)
			linked[i].push_back(i);
		
		solver prob(linked);
		cout << prob.solve() << endl;
	}
	return 0;
}
