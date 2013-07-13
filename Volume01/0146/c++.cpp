#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class solver
{
	vector<vector<double> > dp;
	vector<vector<int> > trace;
	vector<int> d, num;
	int n;
public:
	solver(vector<int>& d, vector<int>& num)
		: dp(16, vector<double>(1<<15, 1e99)), trace(16, vector<int>(1<<15, -1)), d(d), num(num), n(num.size()) {}
	double solve(int pos, int done, int weight)
	{
		if(done == (1<<n)-1) return 0;
		if(dp[pos][done] != 1e99) return dp[pos][done];
		double ret = 1e99;
		for(int i = 0; i < n; i++)
			if(!(done >> i & 1))
			{
				double tmp = solve(i, done | (1<<i), weight + num[i]*20) + (double)abs(d[i]-d[pos])*(70*weight)/2000;
				if(ret > tmp)
				{
					ret = tmp;
					trace[pos][done] = i;
				}
			}
		//cout << pos << "," << done << "," << weight << "," << ret << endl;
		dp[pos][done] = ret;
		return ret;
	}
	void trace_back(vector<int>& no) { trace_back(n, 0, 0, no); }
	void trace_back(int pos, int done, int i, vector<int>& no)
	{
		if(pos != n) cout << (i > 1 ? " " : "") << no[pos];
		if(trace[pos][done] == -1) { cout << endl; return; }
		trace_back(trace[pos][done], done | 1<<trace[pos][done], i+1, no);
	}
};

int main()
{
	int n; cin >> n;
	vector<int> no(n), d(n+1), num(n);
	for(int i = 0; i < n; i++)
		cin >> no[i] >> d[i] >> num[i];
	
	solver prob(d, num);
	prob.solve(n, 0, 0);
	prob.trace_back(no);
	return 0;
}
