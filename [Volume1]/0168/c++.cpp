#include <iostream>
using namespace std;

int main()
{
	unsigned long long step[31] = {1, 1, 2};
	for(int i = 3; i < 31; i++)
	{
		step[i] = step[i-1] + step[i-2] + step[i-3];
	}
	
	int n;
	while(cin >> n, n != 0)
	{
		cout << (step[n]-1)/3650 +1 << endl;
	}
	return 0;
}