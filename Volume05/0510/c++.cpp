#include <iostream>
using namespace std;

int main()
{
	int a[4], b[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2] >> b[3];
	cout << max(a[0]+a[1]+a[2]+a[3], b[0]+b[1]+b[2]+b[3]) << endl;
	return 0;
}