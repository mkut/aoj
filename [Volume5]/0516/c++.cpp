#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	while(cin >> n >> k, n != 0)
	{
		queue<int> q;
		int sum = 0, _max = -1000000;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			q.push(tmp);
			sum += tmp;
			if(q.size() > k)
			{
				sum -= q.front();
				q.pop();
			}
			if(q.size() == k) _max = max(_max, sum);
		}
		cout << _max << endl;
	}
	return 0;
}