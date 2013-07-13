#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100000000

int main()
{
	int n;
	while(cin >> n, n)
	{
		int Min = INF, Max = 0;
		while(n--)
		{
			int a, b, c, d, e;
			cin >> a >> b >> c >> d >> e;
			int sum = a + b + c + d + e;
			Min = min(Min, sum);
			Max = max(Max, sum);
		}
		cout << Max << " " << Min << endl;
	}
	return 0;
}
