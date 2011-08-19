#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

class solver
{
	map<int,int> memo;
	vector<vector<vector<int> > > lnk;
	int num;
public:
	solver(vector<vector<vector<int> > >& lnk) : lnk(lnk), num(lnk.size()) {}
	int solve(int p, int rem)
	{
		int remnum = 0;
		for(int i = 0; i < num; i++)
			if(rem >> i & 1)
				remnum++;
		
		int memoindex = (p<<num)|rem;
		if(memo.count(memoindex))
			return memo[memoindex];
		int ret = 0;
		for(int i = 0; i < 4; i++)
		{
			int next = -1;
			for(int j = 0; j < lnk[p][i].size(); j++)
			{
				if(lnk[p][i][j] == 0 && rem == 1)
				{
					ret++;
					break;
				}
				if(lnk[p][i][j] != 0 && (rem >> lnk[p][i][j] & 1))
				{
					next = lnk[p][i][j];
					break;
				}
			}
			if(next != -1)
			{
				ret += solve(next, rem^(1<<next));
			}
		}
		if(remnum > 5) memo[memoindex] = ret;
		return ret;
	}
};

int main()
{
	int m, n;
	while(cin >> m >> n, m)
	{
		vector<vector<int> > view(n+2, vector<int>(m+2, -1));
		vector<int> xs(1), ys(1);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				cin >> view[i][j];
				if(view[i][j] == 2)
					xs[0] = i, ys[0] = j, view[i][j] = 0; // goal
				else if(view[i][j] == 1)
					view[i][j] = xs.size(), xs.push_back(i), ys.push_back(j); // 1 to num
				else if(view[i][j] == 0)
					view[i][j] = 100; // akiti
			}
		int num = xs.size();
		
		vector<vector<vector<int> > > lnk(num, vector<vector<int> >(4));
		for(int i = 0; i < num; i++)
			for(int k = 0; k < 4; k++)
				for(int X = xs[i] + dx[k], Y = ys[i] + dy[k]; view[X][Y] != -1; X += dx[k], Y += dy[k])
					if(view[X][Y] != 100)
						lnk[i][k].push_back(view[X][Y]);
		solver prob(lnk);
		int ans = prob.solve(0, (1<<num)-1);
		cout << ans << endl;
	}
	return 0;
}
