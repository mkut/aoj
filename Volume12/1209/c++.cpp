#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int solve(int money, int Max)
{
	if(money == 0) return 1;
	if(money < 0) return 0;
	int ret = 0;
	for(int i = 1; i <= Max; i++)
		ret += solve(money - i*i, i);
	return ret;
}

int main()
{
	int n;
	while(cin >> n, n)
		cout << solve(n, 17) << endl;
	return 0;
}
