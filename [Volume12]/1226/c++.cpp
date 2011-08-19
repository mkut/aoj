#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double heron(double a, double b, double c)
{
	double s = (a+b+c)/2;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}

double d(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double area4(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	return heron(d(x1, y1, x2, y2), d(x2, y2, x3, y3), d(x3, y3, x1, y1)) + heron(d(x4, y4, x2, y2), d(x2, y2, x3, y3), d(x3, y3, x4, y4));
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<double> a(n+2), b(n+2), c(n+2), d(n+2);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		for(int i = 1; i <= n; i++)
			cin >> d[i];
		a[n+1] = b[n+1] = c[n+1] = d[n+1] = 1;
		
		vector<vector<double> > x(n+2, vector<double>(n+2)), y(n+2, vector<double>(n+2));
		for(int i = 0; i < n+2; i++)
			for(int j = 0; j < n+2; j++)
				x[i][j] = (c[j] * (b[i] - a[i]) + a[i]) / (1 - (b[i] - a[i]) * (d[j] - c[j])),
				y[i][j] = (a[i] * (d[j] - c[j]) + c[j]) / (1 - (b[i] - a[i]) * (d[j] - c[j]));
		double ans = 0;
		for(int i = 0; i < n+1; i++)
			for(int j = 0; j < n+1; j++)
				ans = max(ans, area4(x[i][j], y[i][j], x[i][j+1], y[i][j+1], x[i+1][j], y[i+1][j], x[i+1][j+1], y[i+1][j+1]));
		printf("%.6f\n", ans);
	}
	return 0;
}
