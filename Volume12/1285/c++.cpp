#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, w;
	while(cin >> n >> w, n)
	{
		vector<int> count;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			if(count.size() <= tmp / w)
				count.resize(tmp / w + 1, 0);
			count[tmp/w]++;
		}
		int y_max = 0;
		for(int i = 0; i < count.size(); i++)
			y_max = max(y_max, count[i]);
		double ans = 0.01;
		for(int i = 0; i < count.size(); i++)
			ans += (1-(double)i / (count.size() - 1)) * count[i] / y_max;
		printf("%.8f\n", ans);
	}
	return 0;
}
