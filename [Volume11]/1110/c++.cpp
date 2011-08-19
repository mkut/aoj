#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<pair<int,int> > Cards;

class solver
{
	vector<int> memo;
public:
	solver() : memo(1<<20, -1) {}
	int solve(Cards c, int done)
	{
		if(~memo[done]) return memo[done];
		
		int ret = c.size();
		for(int i = 0; i < c.size(); i++)
		{
			if(i%4 != 0 && i/4 > 0 && c[i].second == c[i-5].second)
			{
				Cards cc = c;
				int ndone = done | 1<<c[i].first | 1<<c[i-5].first;
				cc.erase(cc.begin() + i);
				cc.erase(cc.begin() + i - 5);
				ret = min(ret, solve(cc, ndone));
			}
			if(i/4 > 0 && c[i].second == c[i-4].second)
			{
				Cards cc = c;
				int ndone = done | 1<<c[i].first | 1<<c[i-4].first;
				cc.erase(cc.begin() + i);
				cc.erase(cc.begin() + i - 4);
				ret = min(ret, solve(cc, ndone));
			}
			if(i%4 != 3 && i/4 > 0 && c[i].second == c[i-3].second)
			{
				Cards cc = c;
				int ndone = done | 1<<c[i].first | 1<<c[i-3].first;
				cc.erase(cc.begin() + i);
				cc.erase(cc.begin() + i - 3);
				ret = min(ret, solve(cc, ndone));
			}
			if(i%4 != 0 && c[i].second == c[i-1].second)
			{
				Cards cc = c;
				int ndone = done | 1<<c[i].first | 1<<c[i-1].first;
				cc.erase(cc.begin() + i);
				cc.erase(cc.begin() + i - 1);
				ret = min(ret, solve(cc, ndone));
			}
		}
		memo[done] = ret;
		return ret;
	}
};

int main()
{
	int n; cin >> n;
	while(n--)
	{
		Cards c(20);
		for(int i = 0; i < 20; i++)
			cin >> c[i].second, c[i].first = i;
		
		solver prob;
		cout << prob.solve(c, 0) << endl;
	}
	return 0;
}
