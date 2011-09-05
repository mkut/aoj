#include <milib/template/aoj>
#include <vector>
#include <cmath>
#include <milib/io/setprec>

class solver
{
	int n, m, k;
	double ans;
public:
	//>>[
	n m k!0 0 0
	//>>]
	//<<[
	_setprec(8) ans
	//<<]

	vector<int> memo;
	void solve()
	{
		memo = vector<int>(n*m+1);
		point(n, m, 0);
		int cnt = 0;
		each(i : memo.size())
			cnt += max(1, i - k) * memo[i];
		ans = cnt / pow(m, n);
	}
	void point(int n, int m, int p)
	{
		if(n == 0)
			memo[p]++;
		else
			each(i : 1...m)
				point(n-1, m, p+i);
	}
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
	}
	return 0;
}
