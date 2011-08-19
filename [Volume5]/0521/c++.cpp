#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int val[] = {1,5,10,50,100,500,1000};
		int ans = 0;
		for(int i = 0; i < 6; i++)
		{
			ans += (1000-n) % val[i+1]/ val[i];
		}
		cout << ans << endl;
	}
	return 0;
}