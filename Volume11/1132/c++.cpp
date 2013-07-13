#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double EPS = 1e-10;
double root2 = sqrt(2);
	
double d2(double x1, double y1, double x2, double y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

struct sq
{
	double L, R, B, T;
	int count;
	sq(double L, double R, double B, double T) : L(L), R(R), B(B), T(T) {}
	void setCount(vector<double>& xs, vector<double>& ys)
	{
		count = 0;
		for(int i = 0; i < xs.size(); i++)
			if(d2(xs[i], ys[i], (L+R)/2, (B+T)/2) - ((R-L)*root2+1)*((R-L)*root2+1) < 0)
				count++;
	}
	bool operator<(const sq& a) const { return count > a.count; }
};

class solver
{
	vector<double> xs, ys;
	int Max;
public:
	solver(vector<double>& xs, vector<double>& ys) : xs(xs), ys(ys), Max(0) {}
	
	int solve(double L, double R, double B, double T)
	{
		int count = 0;
		double X = (L+R)/2, Y = (B+T)/2;
		for(int i = 0; i < xs.size(); i++)
			if(d2(xs[i], ys[i], X, Y) - 1 < EPS)
				count++;
		Max = max(Max, count);
		
		vector<sq> next;
		next.push_back(sq(L, X, B, Y));
		next.push_back(sq(X, R, B, Y));
		next.push_back(sq(L, X, Y, T));
		next.push_back(sq(X, R, Y, T));
		for(int i = 0; i < 4; i++)
			next[i].setCount(xs, ys);
		sort(next.begin(), next.end());
		for(int i = 0; i < 4; i++)
		{
			if(next[i].count <= Max) break;
			solve(next[i].L, next[i].R, next[i].B, next[i].T);
		}
		return Max;
	}
};

int main()
{
	int N;
	while(cin >> N, N)
	{
		vector<double> xs(N), ys(N);
		for(int i = 0; i < N; i++)
			cin >> xs[i] >> ys[i];
		
		solver prob(xs, ys);
		int ans = prob.solve(0.0, 10.0, 0.0, 10.0);
		cout << ans << endl;
	}
	return 0;
}
