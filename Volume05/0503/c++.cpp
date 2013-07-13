#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class solver
{
  private:
	vector<int> lst;
	vector<int> f;
	
  public:
	solver(vector<int> vi)
	{
		lst = vi;
		f = vector<int>(16);
		f[0] = 0;
		for(int i = 1; i <= 15; i++)
		{
			f[i] = 3 * f[i-1] + 2;
		}
	}
	
	int solve()
	{
		return solve(lst.begin());
	}
	
  private:
	int solve(vector<int>::iterator it)
	{
		if(it == lst.end()) return 0;
		
		if(*it == 2)
		{
			return solve(it+1) + 1 + f[distance(it, lst.end())-1];
		}
		else
		{
			return solveLR(it+1, *it);
		}
	}
	int solveLR(vector<int>::iterator it, int dist)
	{
		if(it == lst.end()) return 0;
		
		if(*it == 2)
		{
			return solveLR(it+1, dist==1 ? 3 : 1) + 1 + f[distance(it, lst.end())-1];
		}
		else if(*it == dist)
		{
			return solveLR(it+1, dist);
		}
		else
		{
			return solveLR(it+1, dist) + 2 + 2*f[distance(it, lst.end())-1];
		}
	}
};

void d(vector<int> vi)
{
	for(int i = 0; i < vi.size(); i++)
	{
		cout << vi[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0 || m != 0)
	{
		vector<int> lst(n);
		for(int i = 0; i < 3; i++)
		{
			int num; cin >> num;
			for(int j = 0; j < num; j++)
			{
				int tmp; cin >> tmp;
				lst[tmp-1] = i+1;
			}
		}
		solver prob(lst);
		int ans = prob.solve();
		if(ans <= m) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}