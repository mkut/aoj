#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int A, B;
	while(cin >> A >> B, A)
	{
		int C = B - A;
		cout << C%500/100 << " " << C%1000/500 << " " << C/1000 << endl;
	}
	return 0;
}
