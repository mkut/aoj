#include <iostream>
#include <cmath>
using namespace std;

#define EPS 1e-8
#define sq(x) ((x)*(x))

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		double xa, ya, ra, xb, yb, rb;
		cin >> xa >> ya >> ra >> xb >> yb >> rb;
		
		double d2 = sq(xa-xb) + sq(ya-yb);
		
		int ans;
		if(d2 > sq(ra + rb)) ans = 0;
		else if(d2 < sq(ra + rb) && sq(ra - rb) < d2) ans = 1;
		else if(sq(ra - rb) > d2) ans = ra > rb ? 2 : -2;
		else ans = 1;
		
		cout << ans << endl;
	}
	return 0;
}