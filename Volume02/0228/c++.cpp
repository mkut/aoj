#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int on[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};

int main()
{
	int n;
	while(cin >> n, ~n)
	{
		int cur = 0;
		while(n--)
		{
			int next_num; cin >> next_num;
			int ans = cur ^ on[next_num];
			cur = on[next_num];
			for(int i = 6; i >= 0; i--)
				cout << (ans >> i & 1 ? 1 : 0);
			cout << endl;
		}
	}
	return 0;
}
