#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Prob
{
	int id;
	int n, m, s;
	int ans;
	Prob(int ID, int N, int M, int S) : id(ID), n(N), m(M), s(S) {}
};

bool cmp1(Prob a, Prob b)
{
	return a.n < b.n;
}
bool cmp2(Prob a, Prob b)
{
	return a.id < b.id;
}

int dp[2000][3000] = {};

int main()
{
	vector<Prob> sets;
	int Max_N = 0, Max_M = 0, Max_S = 0;
	for(int No = 0, N, M, S; cin >> N >> M >> S, N; No++)
	{
		int n = N*N; Max_N = max(Max_N, n);
		int m = M - n; Max_M = max(Max_M, m);
		int s = S - n*(n+1)/2; Max_S = max(Max_S, s);
		sets.push_back(Prob(No, n, m, s));
	}
	
	sort(sets.begin(), sets.end(), cmp1);
	vector<Prob>::iterator it = sets.begin();
	dp[0][0] = 1;
	for(int i = 0; i <= Max_N; i++)
	{
		for(int j = 1; j <= Max_M; j++)
			for(int k = i; k <= Max_S; k++)
				dp[j][k] = (dp[j][k] + dp[j-1][k-i]) % 100000;
		
		if(it == sets.end()) break;
		while(it->n == i)
		{
			it->ans = dp[it->m][it->s];
			++it;
		}
	}
	
	sort(sets.begin(), sets.end(), cmp2);
	for(int i = 0; i < sets.size(); i++)
		printf("%d\n", sets[i].ans);
	return 0;
}
