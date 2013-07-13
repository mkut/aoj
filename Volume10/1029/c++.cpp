#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n+m != 0)
	{
		vector<int> time;
		for(int i = 0; i < n+m; i++)
		{
			int tmp; cin >> tmp;
			time.push_back(tmp);
		}
		sort(time.begin(), time.end());
		int _max = 0;
		int prev = 0;
		for(int i = 0; i < time.size(); i++)
		{
			_max = max(_max, time[i]-prev);
			prev = time[i];
		}
		cout << _max << endl;
	}
	return 0;
}