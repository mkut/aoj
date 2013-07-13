#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#include <vector>
#include <limits>
#include <cmath>
template <class Number>
vector<Number> gauss_jordan(vector<vector<Number> > matrix)
{
	//for(int i = 0; i < matrix.size(); i++)
	//	assert(matrix[i].size() == matrix.size()+1);
	
	int n = matrix.size();
	for(int i = 0; i < n; i++)
	{
		for(int j = n; j >= i; j--)
			matrix[i][j] /= matrix[i][i];
		for(int j = 0; j < n; j++)
			for(int k = n; k >= i; k--)
				if(i != j)
					matrix[j][k] -= matrix[i][k] * matrix[j][i] / matrix[i][i];
	}
	vector<Number> ret(n);
	for(int i = 0; i < n; i++)
		ret[i] = matrix[i][n];
	return ret;
}

template <class Number>
struct Point
{
	Number x, y;
	Point() : x(0), y(0) {}
	Point(Number x, Number y) : x(x), y(y) {}
	friend ostream& operator<<(ostream& os, Point a)
	{
		os << "#<Point>(" << a.x << "," << a.y << ")";
		return os;
	}
	bool isnap() { return isnan(x) || isnan(y); }
	static Point nap() { return Point(numeric_limits<Number>::quiet_NaN(), numeric_limits<Number>::quiet_NaN()); }
};

template <class Number>
struct LineSegment
{
	Point<Number> a, b;
	LineSegment() {}
	LineSegment(Point<Number> a, Point<Number> b) : a(a), b(b) {}
	LineSegment(Number xa, Number ya, Number xb, Number yb) : a(xa, ya), b(xb, yb) {}
	friend Point<Number> intersection(LineSegment A, LineSegment B)
	{
		vector<vector<Number> > matrix(2, vector<Number>(3));
		matrix[0][0] = A.a.x-A.b.x; matrix[0][1] = B.b.x-B.a.x; matrix[0][2] = B.b.x - A.b.x;
		matrix[1][0] = A.a.y-A.b.y; matrix[1][1] = B.b.y-B.a.y; matrix[1][2] = B.b.y - A.b.y;
		vector<Number> param = gauss_jordan(matrix);
		Point<Number> ret(param[0]*A.a.x+(1-param[0])*A.b.x, param[0]*A.a.y+(1-param[0])*A.b.y);
		if(ret.x - min(A.a.x, A.b.x) > -1e-10  && ret.x - max(A.a.x, A.b.x) < 1e-10 && ret.y - min(A.a.y, A.b.y) > -1e-10 && ret.y - max(A.a.y, A.b.y) < 1e-10 &&
			ret.x - min(B.a.x, B.b.x) > -1e-10  && ret.x - max(B.a.x, B.b.x) < 1e-10 && ret.y - min(B.a.y, B.b.y) > -1e-10 && ret.y - max(B.a.y, B.b.y) < 1e-10)
			return ret;
		else
			return Point<Number>::nap();
	}
	friend ostream& operator<<(ostream& os, LineSegment a)
	{
		os << "#<LineSegment>{" << a.a << "-" << a.b << "}";
		return os;
	}
};

bool cmp(pair<bool, Point<double> > a, pair<bool, Point<double> > b)
{ return a.second.x < b.second.x; }

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
		LineSegment<double> newLine(xa, ya, xb, yb);
		int n; cin >> n;
		vector<pair<bool, Point<double> > > iss;
		for(int i = 0; i < n; i++)
		{
			int xs, ys, xt, yt, o, l; cin >> xs >> ys >> xt >> yt >> o >> l;
			LineSegment<double> oldLine(xs, ys, xt, yt);
			Point<double> is = intersection(newLine, oldLine);
			if(!is.isnap())
				iss.push_back(make_pair(o^l, is));
		}
		sort(iss.begin(), iss.end(), cmp);
		int ans = 0;
		for(int i = 1; i < iss.size(); i++)
			if(iss[i-1].first != iss[i].first)
				ans++;
		cout << ans << endl;
	}
	return 0;
}
