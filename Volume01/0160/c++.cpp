#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	const int size[7] = {60, 80, 100, 120, 140, 160, 100000000};
	const int weight[7] = {2, 5, 10, 15, 20, 25, 100000000};
	const int price[7] = {600, 800, 1000, 1200, 1400, 1600, 0};
	while(cin >> n, n != 0)
	{
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			int x, y, h, w;
			cin >> x >> y >> h >> w;
			for(int i = 0; i < 7; i++)
			{
				if(x+y+h <= size[i] && w <= weight[i])
				{
					sum += price[i];
					break;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}