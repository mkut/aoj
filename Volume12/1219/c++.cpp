#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct state
{
	int id, time, cycle;
	state(int id, int time, int cycle) : id(id), time(time), cycle(cycle) {}
	bool operator<(const state& a) const { return time > a.time || time == a.time && id > a.id; }
};

int main()
{
	int n, t;
	while(cin >> n >> t, n)
	{
		vector<vector<int> > pattern(n);
		for(int i = 0; i < n; i++)
		{
			int tmp;
			while(cin >> tmp, tmp)
				pattern[i].push_back(tmp);
		}
		
		priority_queue<state> Q;
		for(int i = 0; i < n; i++)
			Q.push(state(i, pattern[i][0], 0));
		
		int ans = 0, idle_time = 0;
		while(!Q.empty())
		{
			state cur = Q.top(); Q.pop();
			int id = cur.id, time = cur.time, cycle = cur.cycle;
			vector<int>& cur_pattern = pattern[id];
			int L = cur_pattern.size();
			//printf("[%d]idle:%d %d~%d waste:%d\n", id+1, idle_time, max(idle_time, time), max(idle_time, time) + cur_pattern[(cycle+1)%L], max(0, idle_time - time));
			ans += max(0, idle_time - time);
			idle_time = min(max(idle_time, time) + cur_pattern[(cycle+1)%L], t);
			if(idle_time + cur_pattern[(cycle+2)%L] < t)
				Q.push(state(cur.id, idle_time + cur_pattern[(cycle+2)%L], (cycle+2)%L));
		}
		cout << ans << endl;
	}
	return 0;
}
