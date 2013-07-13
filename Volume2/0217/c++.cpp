#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n)
	{
		int maxID = 0, maxLength = -1;
		for(int i = 0; i < n; i++)
		{
			int p, d1, d2; cin >> p >> d1 >> d2;
			if(maxLength < d1+d2)
				maxID = p, maxLength = d1+d2;
		}
		cout << maxID << " " << maxLength << endl;
	}
	return 0;
}
