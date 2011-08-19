#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	while(cin >> a >> b >> c, a)
	{
		int P = -1, Q = 0, R = 0, S = 0;
		if(c == 0)
		{
			P = a, Q = b, R = 1, S = 0;
		}
		else
		{
			for(int r = 1; r*r <= a; r++)
			{
				if(a % r == 0)
				{
					int p = a/r;
					for(int q = 1; q*q <= abs(c); q = q>0 ? -q : -q+1)
					{
						if(c / q * q == c)
						{
							int s = c/q;
							for(int i = 0; i < 2; i++, swap(q, s))
							{
								if(q * r + p * s == b)
								{
									P = p, Q = q, R = r, S = s;
									goto end;
								}
							}
						}
					}
				}
			}
		}
end:;
		if(P == R && Q < S)
			swap(Q, S);
		if(P == -1)
			cout << "Impossible" << endl;
		else
			cout << P << " " << Q << " " << R << " " << S << endl;
	}
	return 0;
}
