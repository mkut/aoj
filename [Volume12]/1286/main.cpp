#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
struct setprec;


struct setprec {
	int width;
	setprec(int width) : width(width) {}
	friend ostream& operator<<(ostream& os, setprec prec) {
		os << setiosflags(ios::fixed) << setprecision(prec.width) << showpoint;
		return os;
	}
};
using namespace std;
struct setprec;

class solver
{
	int n, m, k;
	double ans;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.n >> cl.m >> cl.k;
		if(cl.n == 0 && cl.m == 0 && cl.k == 0)
			is.setstate(ios::badbit);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << setprec(8) << cl.ans << endl;
		return os;
	}

	vector<int> memo;
	void solve()
	{
		memo = vector<int>(n*m+1);
		point(n, m, 0);
		int cnt = 0;
		for(int i = 0; i < memo.size(); i++)
			cnt += max(1, i - k) * memo[i];
		ans = cnt / pow(m, n);
	}
	void point(int n, int m, int p)
	{
		if(n == 0)
			memo[p]++;
		else
			for(int i = 1; i <= m; i++)
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
