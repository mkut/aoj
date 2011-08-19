#include <iostream>
using namespace std;

int main()
{
	int N;
	while(cin >> N, N != 0)
	{
		int sum = 0;
		for(int i = 0; i < N*(N-1)/2; i++)
		{
			int tmp; cin >> tmp;
			sum += tmp;
		}
		cout << sum / (N-1) << endl;
	}
	return 0;
}