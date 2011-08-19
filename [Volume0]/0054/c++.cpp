#include <iostream>
using namespace std;

int main()
{
	int a, b, n;
	while(cin >> a >> b >> n)
	{
		int sum = 0;
		
		while(n--)
		{
			a = a % b * 10;
			sum += a / b;
		}
		
		cout << sum << endl;
	}
	return 0;
}