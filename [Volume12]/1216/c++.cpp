#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct point
{
	double x, y, z;
	point() {}
};

double d(point a, point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		double QR, RP, PQ; cin >> QR >> RP >> PQ;
		int n; cin >> n;
		vector<point> ps(n);
		for(int i = 0; i < n; i++)
			cin >> ps[i].x >> ps[i].y >> ps[i].z;
			
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				for(int k = 0; k < n; k++)
				{
					if(i == k || j == k) continue;
					double r[3];
					r[0] = d(ps[j], ps[k]) / QR;
					r[1] = d(ps[k], ps[i]) / RP;
					r[2] = d(ps[i], ps[j]) / PQ;
					bool ok = true;
					for(int a = 0; a < 3; a++)
						if(r[a] / r[(a+1)%3] < 0.9995 || r[a] / r[(a+1)%3] > 1.0005)
							ok = false;
					if(ok)
					{
						cout << i+1 << " " << j+1 << " " << k+1 << endl;
						goto loopend;
					}
				}
			}
		}
loopend:
		continue;
	}
	return 0;
}
