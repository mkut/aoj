#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int ans[7] = {};
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			if(tmp >= 60) ans[6]++;
			else ans[tmp/10]++;
		}
		for(int j = 0; j < 7; j++)
		{
			cout << ans[j] << endl;
		}
	}
	return 0;
}