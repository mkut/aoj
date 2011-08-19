/* aoj header */
#include <vector>
#include <cmath>

int main()
{
	vector<double> ans(100001);
	vector<double> memo(100001);

	for(int i = 1; i <= 100000; i++)
	{
		for(int j = 0; j <= 30 && i-j-1 >= 0; j++)
			memo[i] += (1 - memo[i-j-1]) / pow(2, j*(j+1)/2);
		ans[i] = ans[i-1] + memo[i];
	}

	int n;
	while(cin >> n, n)
		printf("%.8f\n", ans[n]);
	return 0;
}

