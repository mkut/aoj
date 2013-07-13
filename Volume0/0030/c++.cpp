#include <iostream>
using namespace std;

int solve(int prev, int n, int s)
{
	if(n == 0 && s == 0) return 1;
	if(n == 0) return 0;
	if(s < 0) return 0;
	
	int ret = 0;
	for(int i = prev + 1; i < 10; i++)
	{
		ret += solve(i, n-1, s-i);
	}
	return ret;
}

int main()
{
	int n, s;
	while(cin >> n >> s, n != 0 || s != 0)
	{
		cout << solve(-1, n, s) << endl;
	}
	return 0;
}