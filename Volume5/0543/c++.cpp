#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int ans;
	while(cin >> ans, ans)
	{
		for(int i = 0; i < 9; i++)
		{
			int tmp; cin >> tmp;
			ans -= tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
