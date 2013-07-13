#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<pair<int, int> > lst;
		for(int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			int time = 0;
			for(int i = 0; i < 4; i++)
			{
				int m, s;
				cin >> m >> s;
				time += m*60 +s;
			}
			lst.push_back(pair<int,int>(number, time));
		}
		sort(lst.begin(), lst.end(), cmp);
		cout << lst[0].first << endl << lst[1].first << endl << lst[lst.size()-2].first << endl;
	}
	return 0;
}