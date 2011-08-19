#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first;
}

class solver
{
  private:
	vector<pair<int,int> > numamo;
	vector<int> sum;
	
  public:
	solver(vector<pair<int, int> > numamo)
	{
		this->numamo = numamo;
		int s = 0;
		for(int i = numamo.size()-1; i >= 0; i--)
		{
			s += numamo[i].first * numamo[i].second;
			sum.push_back(s);
		}
		reverse(sum.begin(), sum.end());
	}
	
  public:
	int solve(int n)
	{
		return _solve(0, n, numamo[0].second);
	}
  private:
	int _solve(int index, int remain, int remamount)
	{
		if(remain == 0) return 1;
		if(remain < 0) return 0;
		if(remain > sum[index]) return 0;
		
		int r = 0;
		if(remamount > 0)
		{
			r += _solve(index, remain - numamo[index].first, remamount-1);
		}
		for(int i = index+1; i < numamo.size(); i++)
		{
			if(numamo[i].second > 0)
			{
				r += _solve(i, remain - numamo[i].first, numamo[i].second-1);
			}
		}
		return r;
	}
};

int main()
{
	int m;
	while(cin >> m, m != 0)
	{
		vector<pair<int,int> > numamo;
		for(int i = 0; i < m; i++) 
		{
			int tmp1, tmp2; cin >> tmp1 >> tmp2;
			numamo.push_back(pair<int,int>(tmp1,tmp2));
		}
		sort(numamo.begin(), numamo.end(), cmp);
		solver prob(numamo);
		int g;
		cin >> g;
		for(int i = 0; i < g; i++)
		{
			int tmp; cin >> tmp;
			cout << prob.solve(tmp) << endl;
		}
	}
	return 0;
}