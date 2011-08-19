#include <iostream>
#include <algorithm>
#include <vector>
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
		vector<pair<int,int> > vec(n);
		for(int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			vec[i] = pair<int,int>(a, b);
		}
		
		sort(vec.begin(), vec.end(), cmp);
		
		int sum = 0;
		bool ok = true;
		for(int i = 0; i < n; i++)
		{
			if(sum + vec[i].first > vec[i].second)
			{
				ok = false;
				break;
			}
			sum += vec[i].first;
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
	return 0;
}
