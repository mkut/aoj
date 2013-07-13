#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int _max = 0, _min = 10000, sum = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			_max = max(_max, tmp);
			_min = min(_min, tmp);
			sum += tmp;
		}
		cout << (sum - _max - _min) / (n-2) << endl;
	}
	return 0;
}
