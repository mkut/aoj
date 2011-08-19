#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct task
{
	int time, weight;
	task(int time, int weight) : time(time), weight(weight) {}
	bool operator<(const task& a) const { return time < a.time || time == a.time && weight < a.weight; }
};

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<task> tasks;
		for(int i = 0; i < n; i++)
		{
			int m, a, b; cin >> m >> a >> b;
			tasks.push_back(task(a, m));
			tasks.push_back(task(b, -m));
		}
		sort(tasks.begin(), tasks.end());
		int cur = 0;
		bool ok = true;
		for(int i = 0; i < tasks.size(); i++)
			cur += tasks[i].weight, ok &= cur <= 150;
		cout << (ok ? "OK" : "NG") << endl;
	}
	return 0;
}
