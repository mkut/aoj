#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second || (a.second == b.second && a.first < b.first);
}

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0 || m != 0)
	{
		vector<int> score(m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				int tmp; cin >> tmp;
				score[j] += tmp;
			}
		}
		
		vector<pair<int,int> > num_score(m);
		for(int i = 0; i < m; i++) num_score[i] = pair<int,int>(i+1, score[i]);
		
		sort(num_score.begin(), num_score.end(), cmp);
		
		bool first = true;
		for(int i = 0; i < m; i++)
		{
			cout << (first ? "" : " ") << num_score[i].first;
			first = false;
		}
		cout << endl;
	}
	return 0;
}