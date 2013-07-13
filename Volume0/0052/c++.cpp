#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int ans = 0;
		for(n /= 5; n != 0; n /= 5) ans += n;
		cout << ans << endl;
	}
	return 0;
}