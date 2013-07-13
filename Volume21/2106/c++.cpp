#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class solver
{
  private:
	map<vector<int>::iterator, map<pair<int,int>, int> > _max;
	vector<int> E;
	
  public:
	solver(vector<int> E)
	{
		this->E = E;
	}
	
	int solve()
	{
		if(E.begin()+1 == E.end()) return E[0];
		return _solve(E.begin(), E[0], E[1]);
	}
	
  private:
	int _solve(vector<int>::iterator it, int prev, int cur)
	{
		if(it+2 == E.end()) return cur;
		
		if(_max[it].count(pair<int,int>(prev,cur)) == 0)
		{
			_max[it][pair<int,int>(prev,cur)] = _solve(it+1, cur, *(it+2));
			if(cur > 0)
			{
				_max[it][pair<int,int>(prev,cur)] = max(_max[it][pair<int,int>(prev,cur)], _solve(it+1, cur-1, *(it+2)+prev));
			}
		}
		return _max[it][pair<int,int>(prev,cur)];
	}
};

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int L;
		cin >> L;
		vector<int> E;
		for(int i = 0; i < L; i++)
		{
			int tmp;
			cin >> tmp;
			E.push_back(tmp);
		}
		
		solver prob(E);
		cout << prob.solve() << endl;
		
	}
	return 0;
}

// 3 4 0 2 0 0 1 0 3 4 2 0 1 4 2 3 0 3 1 2
// 3 4 