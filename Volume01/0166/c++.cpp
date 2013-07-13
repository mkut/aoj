#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n, n != 0)
	{
		double s1 = 0, s2 = 0;
		int remain = 360;
		for(int i = 0; i < n-1; i++)
		{
			int tmp; cin >> tmp;
			s1 += sin(M_PI/180*tmp);
			remain -= tmp;
		}
		s1 += sin(M_PI/180*remain);
		cin >> m;
		remain = 360;
		for(int i = 0; i < m-1; i++)
		{
			int tmp; cin >> tmp;
			s2 += sin(M_PI/180*tmp);
			remain -= tmp;
		}
		s2 += sin(M_PI/180*remain);
		if(fabs(s1 - s2) < 1e-6) cout << 0 << endl;
		else if(s1 > s2) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}