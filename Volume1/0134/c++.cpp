#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++)
	{
		long long tmp;
		cin >> tmp;
		sum += tmp;
	}
	cout << sum / n << endl;
	return 0;
}