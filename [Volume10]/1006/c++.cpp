#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class solver
{
  private:
	vector<vector<pair<int,int> > > cm;
	
  public:
	solver(vector<vector<pair<int, int> > > cm)
	{
		this->cm = cm;
	}
	
	int solve(int start, int end)
	{
		int _max = 0;
		int cur = 0;
		for(int time = start; time < end; )
		{
			int nexttime = -10000;
			for(int i = 0; i < cm.size(); i++)
			{
				nexttime = max(nexttime, min(end, next(i, time)));
			}
			if(nexttime > 0)
			{
				cur += nexttime - time;
				time = nexttime;
				_max = max(_max, cur);
			}
			else
			{
				time = -nexttime;
				cur = 0;
			}
		}
		return _max;
	}
	
  private:
	int next(int ch, int time)
	{
		for(vector<pair<int,int> >::iterator it = cm[ch].begin(); it != cm[ch].end(); it++)
		{
			if(time < it->first)
			{
				return it->first;
			}
			if(time < it->second)
			{
				return -(it->second);
			}
		}
		return 24*60;
	}
};

int cnv(int time)
{
	return time/100*60 + time%100;
}

int main()
{
	int n, start, end;
	while(cin >> n >> start >> end, n != 0)
	{
		start = cnv(start);
		end = cnv(end);
		
		vector<vector<pair<int,int> > > cm;
		
		for(int i = 0; i < n; i++)
		{
			cm.push_back(vector<pair<int,int> >());
			int k;
			cin >> k;
			for(int j = 0; j < k; j++)
			{
				int tmp1, tmp2;
				cin >> tmp1 >> tmp2;
				cm[i].push_back(pair<int,int>(cnv(tmp1), cnv(tmp2)));
			}
		}
		
		solver prob(cm);
		cout << prob.solve(start, end) << endl;
	}
	return 0;
}