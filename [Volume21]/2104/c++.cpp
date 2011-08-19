#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> distance;
		int prev;
		cin >> prev;
		for(int i = 1; i < n; i++)
		{
			int cur;
			cin >> cur;
			distance.push_back(cur-prev);
			prev = cur;
		}
		
		if(n < k)
		{
			cout << 0 << endl;
			continue;
		}
		sort(distance.begin(), distance.end());
		int sum = 0;
		for(int i = 0; i < n-k; i++)
		{
			sum += distance[i];
		}
		cout << sum << endl;
	}
	return 0;
}