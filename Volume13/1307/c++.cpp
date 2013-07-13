#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
using namespace std;


class solver
{
	set<vector<int> > ret;
	int size;
	int N;
public:
	solver(int Size) : size(Size) {}
	
	set<vector<int> >& solve(vector<int> ps, multiset<int> rem)
	{
		if(rem.empty())
		{
			sort(ps.begin(), ps.end());
			ret.insert(ps);
			return ret;
		}
		
		int pos = *rem.rbegin();
		multiset<int>::iterator tmpit = rem.end();
		for(int i = 0; i < 2; i++)
		{
			bool ok = true;
			multiset<int> nextrem = rem;
			for(int i = 0; i < ps.size(); i++)
			{
				int d = abs(ps[i] - pos);
				multiset<int>::iterator find = nextrem.find(d);
				if(find != nextrem.end())
					nextrem.erase(find);
				else
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				vector<int> nextps = ps;
				nextps.push_back(pos);
				solve(nextps, nextrem);
			}
			pos = size - pos;
		}
		return ret;
	}
};

int main()
{
	int N;
	while(cin >> N, N)
	{
		int size; cin >> size;
		multiset<int> ds;
		for(int i = 1; i < N*(N-1)/2; i++)
		{
			int tmp; cin >> tmp;
			ds.insert(ds.begin(), tmp);
		}
		
		solver prob(size);
		vector<int> origin(2); origin[1] = size;
		set<vector<int> > ans = prob.solve(origin, ds);
		for(set<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			for(int j = 1; j < it->size(); j++)
			{
				if(j > 1) cout << " ";
				cout << (*it)[j] - (*it)[j-1];
			}
			cout << endl;
		}
		cout << "-----" << endl;
	}
	return 0;
}
