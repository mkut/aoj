#include <iostream>
using namespace std;

int solve(int num)
{
	if(num == 1) return 0;
	if(num % 2 == 0) return solve(num/2) + 1;
	else return solve((num*3+1)/2)+2;
}

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		cout << solve(n) << endl;
	}
	return 0;
}