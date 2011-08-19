#include <iostream>
using namespace std;

int mid(int x)
{
	return x / 100 % 10000;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		printf("Case %d:\n", i);
		int s;
		cin >> s;
		for(int j = 0; j < 10; j++)
		{
			s = mid(s*s);
			cout << s << endl;
		}
	}
	return 0;
}