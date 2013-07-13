#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS 1e-4

int main()
{
	double memo[12];
	for(int i = 0; i < 12; i++)
		memo[i] = pow(2.0, 7-i);
	
	double n;
	while(cin >> n, n >= 0)
	{
		int ans[12] = {};
		for(int i = 0; i < 12; i++)
			if(memo[i] - n < EPS)
				n -= memo[i], ans[i] = 1;
		
		if(n < EPS)
		{
			for(int i = 0; i < 8; i++)
				cout << ans[i];
			cout << '.';
			for(int i = 8; i < 12; i++)
				cout << ans[i];
			cout << endl;
		}
		else cout << "NA" << endl;
	}
	return 0;
}
