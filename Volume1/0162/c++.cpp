#include <iostream>
using namespace std;

int main()
{
	int ans[1000001] = {0};
	for(int i = 1; i <= 1000001; i++)
	{
		int tmp = i;
		while(tmp%2 == 0) tmp/=2;
		while(tmp%3 == 0) tmp/=3;
		while(tmp%5 == 0) tmp/=5;
		ans[i] = ans[i-1] + (tmp == 1 ? 1 : 0);
	}
	
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		cout << ans[m] - ans[n-1] << endl;
	}
	return 0;
}