#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class solver
{
  private:
	map<vector<int>, int> ans;
	
  public:
	solver()
	{
		solve();
	}
	
	int getAnswer(vector<int> p)
	{
		return ans[p];
	}
	void solve()
	{
		vector<int> tmp;
		for(int i = 0; i < 8; i++) tmp.push_back(i);
		vector<vector<int> > beginlist;
		beginlist.push_back(tmp);
		_solve(beginlist, 0);
	}
	
  private:
	void _solve(vector<vector<int> > states, int num)
	{
		if(states.size() == 0) return;
		
		vector<vector<int> > nextlist;
		for(vector<vector<int> >::iterator it = states.begin(); it != states.end(); it++)
		{
			ans[*it] = num;
			const int flippos[8][3] = {{1,4,-1}, {0,2,5}, {1,3,6}, {2,7,-1}, {0,5,-1}, {1,4,6}, {2,5,7}, {3,6,-1}};
			
			for(int i = 0; i < 8; i++)
			{
				if((*it)[i] == 0)
				{
					for(int j = 0; j < 3; j++)
					{
						if(flippos[i][j] != -1)
						{
							vector<int> tmp = *it;
							swap(tmp[i],tmp[flippos[i][j]]);
							if(ans.count(tmp) == 0) nextlist.push_back(tmp);
						}
					}
					break;
				}
			}
		}
		_solve(nextlist, num+1);
	}
	
	void d(vector<int> v)
	{
		for(int i = 0; i < 8; i++) cout << v[i];
		cout << endl;
	}
};

int main()
{
	solver prob;
	int input[8];
	while(cin >> input[0])
	{
		for(int i = 1; i < 8; i++) cin >> input[i];
		vector<int> vi;
		for(int i = 0; i < 8; i++) vi.push_back(input[i]);
		cout << prob.getAnswer(vi) << endl;
	}
	return 0;
}