#include <iostream>
using namespace std;

int solve(int n, int s, int numset)
{
	if(n == 0 && s == 0) return 1;
	else if(n == 0) return 0;
	else if(s > n*n*9) return 0;
	
	int ret = 0;
	for(int i = 0; i <= 9; i++)
	{
		if(i*n > s) break;
		if(numset & (1<<i))
		{
			ret += solve(n-1, s-i*n, numset ^ (1<<i));
		}
	}
	return ret;
}

int main()
{
	int n, s;
	while(cin >> n >> s)
	{
		cout << solve(n, s, 0x3FF) << endl;
	}
	return 0;
}