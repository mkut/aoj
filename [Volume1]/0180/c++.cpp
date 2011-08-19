#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

typedef pair<int,int> edge;
typedef pair<edge,int> bridge;

bool cmp(bridge a, bridge b)
{
	return a.second > b.second;
}

bool _removable(vector<bridge>& bs, int pos, bitset<100>& used, int goal)
{
	if(pos == goal) return true;
	for(int i = 0; i < bs.size(); i++)
	{
		if(bs[i].first.first == pos && !used[bs[i].first.second])
		{
			used[bs[i].first.second] = true;
			if(_removable(bs, bs[i].first.second, used, goal)) return true;
		}
		if(bs[i].first.second == pos && !used[bs[i].first.first])
		{
			used[bs[i].first.first] = true;
			if(_removable(bs, bs[i].first.first, used, goal)) return true;
		}
	}
	return false;
}
bool removable(vector<bridge>& bs, bridge b)
{
	bitset<100> used;
	used[b.first.first] = true;
	for(int i = 0; i < bs.size(); i++)
	{
		if(bs[i].first.first == b.first.first && bs[i].first.second != b.first.second)
		{
			used[bs[i].first.second] = true;
			if(_removable(bs, bs[i].first.second, used, b.first.second)) return true;
		}
		if(bs[i].first.second == b.first.first && bs[i].first.first != b.first.second)
		{
			used[bs[i].first.first] = true;
			if(_removable(bs, bs[i].first.first, used, b.first.second)) return true;
		}
	}
	return false;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<bridge> bs;
		for(int i = 0; i < m; i++)
		{
			int a, b, cost;
			cin >> a >> b >> cost;
			bs.push_back(bridge(edge(a,b),cost));
		}
		
		sort(bs.begin(), bs.end(), cmp);
		for(int i = 0; i < bs.size(); i++)
		{
			if(removable(bs, bs[i]))
			{
				bs.erase(bs.begin()+i);
				i--;
			}
		}
		
		int sum = 0;
		for(int i = 0; i < bs.size(); i++)
		{
			sum += bs[i].second;
		}
		cout << sum << endl;
	}
	return 0;
}