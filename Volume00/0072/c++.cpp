#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

bool order(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
	return a.second < b.second;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		cin.ignore(100, '\n');
		vector<pair<pair<int,int>,int> > route;
		for(int i = 0; i < m; i++)
		{
			string sa, sb, scost;
			getline(cin ,sa, ',');
			getline(cin ,sb, ',');
			getline(cin ,scost);
			route.insert(route.end(), pair<pair<int,int>,int>(pair<int,int>(atoi(sa.c_str()),atoi(sb.c_str())), atoi(scost.c_str())/100-1));
		}
		sort(route.begin(), route.end(), order);
		
		int count = 0;
		int connected[100];
		for(int i = 0; i < n; i++) connected[i] = i;
		for(; route.begin() != route.end();)
		{
			vector<pair<pair<int,int>,int> >::iterator it = route.begin();
			count += it->second;
			int prev = max(connected[it->first.first], connected[it->first.second]);
			for(int i = 0; i < n; i++)
			{
				if(connected[i] == prev) connected[i] = min(connected[it->first.first], connected[it->first.second]);
			}
			for(vector<pair<pair<int,int>,int> >::iterator it2 = it; it2 != route.end(); it2++)
			{
				if(connected[it2->first.first] == connected[it2->first.second])
				{
					it2 = route.erase(it2)-1;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}