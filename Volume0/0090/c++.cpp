#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define EPS 1e-6

struct point
{
	double x, y;
	
	point() { point(0,0); }
	point(double X, double Y) : x(X), y(Y) {}
};

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second > b.second;
}

struct solver
{
	vector<point> vp;
	int ans;
	solver(vector<point> VP) : vp(VP), ans(0) {}
	
	int solve(double L, double R, double B, double T, int big)
	{
		//cout << L << "," << R << "," << B << "," << T << endl;
		if(R-L < EPS) return ans;
		
		double X = (L+R)/2, Y = (B+T)/2;
		int c = count(X, Y, 1);
		ans = max(ans, c);
		
		if(ans >= big) return ans;
		else
		{
			double R2 = sqrt((R-L)*(R-L)+(T-B)*(T-B))/2 + 1;
			R2 *= R2;
			double para[4][4] = {
				{L, X, B, Y},
				{L, X, Y, T},
				{X, R, B, Y},
				{X, R, Y, T},
			};
			pair<int,int> lst[4];
			for(int i = 0; i < 4; i++)
			{
				lst[i].first = i;
				lst[i].second = count((para[i][0]+para[i][1])/2, (para[i][2]+para[i][3])/2, R2);
			}
			sort(lst, lst+4, cmp);
			for(int i = 0; i < 4; i++)
			{
				int I = lst[i].first;
				solve(para[I][0], para[I][1], para[I][2], para[I][3], lst[i].second);
			}
		}
		return ans;
	}
	
	int count(double X, double Y, double R2)
	{
		int c = 0;
		for(int i = 0; i < vp.size(); i++)
			if((X-vp[i].x)*(X-vp[i].x) + (Y-vp[i].y)*(Y-vp[i].y) - R2 < EPS)
				c++;
		return c;
	}
};

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<point> vp(N);
		for(int i = 0; i < N; i++)
		{
			double a, b; scanf("%lf,%lf", &a, &b);
			vp[i] = point(a,b);
		}
		
		solver prob(vp);
		int ans = prob.solve(0, 10, 0, 10, N);
		cout << ans << endl;
	}
	return 0;
}
