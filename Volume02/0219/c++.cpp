#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		int num[10] = {};
		while(n--)
		{
			int tmp; cin >> tmp; num[tmp]++;
		}
		for(int i = 0; i < 10; i++)
		{
			if(num[i] == 0) cout << "-" << endl;
			else cout << string(num[i], '*') << endl;
		}
	}
	return 0;
}
