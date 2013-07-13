#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <vector>
#include <set>

struct Program
{
	string name;
	int time;
	Program(string name, int time) : name(name), time(time) {}
	bool operator<(const Program& a) const { return time < a.time; }
};

bool can_watch(set<int>& vi, int i)
{
	set<int>::iterator it = vi.lower_bound(i);
	if(it != vi.end() && *it - 30 < i)
		return false;
	if(it == vi.begin())
		return true;
	--it;
	if(*it + 30 > i)
		return false;
	return true;
}

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<Program> ps;
		for(int i = 0; i < N; i++)
		{
			string name;
			int w, t;
			cin >> name >> w >> t;
			int time = w * 24 * 60 + t/100 * 60 + t%100;
			ps.push_back(Program(name, time));
		}
		sort(ps.begin(), ps.end());

		int P; cin >> P;
		set<int> reqs;
		for(int i = 0; i < P; i++)
		{
			string name; cin >> name;
			for(int j = 0; j < ps.size(); j++)
			{
				if(ps[j].name == name)
				{
					reqs.insert(ps[j].time);
					ps.erase(ps.begin() + j);
					break;
				}
			}
		}

		int ans = P;
		for(set<int>::iterator it = reqs.begin(); it != reqs.end(); ++it)
		{
			set<int>::iterator it2 = it;
			advance(it2, 1);
			if(it2 == reqs.end())
				break;
			if(*it + 30 > *it2)
				ans = -1;
		}
		
		if(ans != -1)
		{
			for(int i = 0; i < ps.size(); i++)
			{
				if(can_watch(reqs, ps[i].time))
				{
					reqs.insert(ps[i].time);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
