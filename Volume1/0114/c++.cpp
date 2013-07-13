#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
	return x % y == 0 ? y : gcd(y, x % y);
}
unsigned long long lcm(unsigned long long x, unsigned long long y)
{
	return x / gcd(x, y) * y;
}
unsigned long long lcm(unsigned long long x, unsigned long long y, unsigned long long z)
{
	return lcm(lcm(x,y),z);
}

int main()
{
	unsigned long long a[3], m[3];
	while(cin >> a[0] >> m[0] >> a[1] >> m[1] >> a[2] >> m[2], a[0] != 0)
	{
		unsigned long long tmp[3];
		for(unsigned long long i = 0; i < 3; i++)
		{
			tmp[i] = 1;
			for(unsigned long long j = a[i] % m[i]; j != 1; j = (j*a[i]) % m[i])
			{
				tmp[i]++;
			}
		}
		cout << lcm(tmp[0], tmp[1], tmp[2]) << endl;
	}
	return 0;
}