#include <iostream>
#include <vector>
using namespace std;

class solver
{
  public:
	vector<string> ans;
	
	solver(int n)
	{
		for(int i = 0; i < n; i++)
		{
			ans.push_back("");
			for(int j = 0; j < n; j++)
			{
				ans[i] += " ";
			}
		}
	}
	
	void solve(int lt, int size)
	{
		if(size <= 0) return;
		if(size == 1)
		{
			ans[lt][lt] = '#';
			return;
		}
		for(int i = lt; i < lt + size; i++)
		{
			ans[lt][i] = '#';
			ans[lt+size-1][i] = '#';
			ans[i][lt] = '#';
			ans[i][lt+size-1] = '#';
		}
		ans[lt+size-1][lt+1] = ' ';
		if(size > 4) ans[lt+size-2][lt+2] = '#';
		solve(lt+2, size-4);
	}
};

int main()
{
	int t;
	cin >> t;
	bool fst = true;
	while(t--)
	{
		if(!fst) cout << endl;
		fst = false;
		
		int n;
		cin >> n;
		solver prob(n);
		prob.solve(0, n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << prob.ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}