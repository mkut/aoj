#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		bool ans = true;
		int big = 0;
		int small = 0;
		int cur;
		for(int i = 0; i < 10; i++)
		{
			cin >> cur;
			if(cur > big) big = cur;
			else if(cur > small) small = cur;
			else ans = false;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}