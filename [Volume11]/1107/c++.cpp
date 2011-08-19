#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define EPS 1e-8

double norm(double x, double y)
{
	return sqrt(x*x+y*y);
}

double get_angle(double x1, double y1, double x2, double y2)
{
	return (x1 * x2 + y1 * y2) / norm(x1, y1) / norm(x2, y2);
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<double> x(n), y(n);
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		
		double X = 0, Y = 0;
		double dx = 0, dy = 1;
		
		double ans = 0;
		while(x.size())
		{
			int max_i = 0;
			double max_angle = -1, max_dist = 0;
			for(int i = 0; i < x.size(); i++)
			{
				double angle = get_angle(dx, dy, x[i]-X, y[i]-Y);
				double dist = norm(x[i]-X, y[i]-Y);
				if(angle - max_angle > EPS || fabs(angle - max_angle) < EPS && max_dist > dist)
					max_angle = angle, max_i = i, max_dist = dist;
			}
			//cout << X << "," << Y << endl;
			dx = x[max_i]-X; dy = y[max_i]-Y;
			X = x[max_i]; Y = y[max_i];
			ans += max_dist;
			x.erase(x.begin() + max_i); y.erase(y.begin() + max_i);
		}
		printf("%.1f\n", ans);
	}
	return 0;
}
