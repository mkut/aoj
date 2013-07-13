#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

template <class T>
struct segment
{
	vector<pair<T, T> > segs;
	segment() {}
	segment(T begin, T end) : segs(1, pair<T, T>(begin, end)) {}
	segment(vector<pair<T, T> >& segs) : segs(segs) {}
	T size()
	{
		T ret = 0;
		for(int i = 0; i < segs.size(); i++)
			ret += segs[i].second - segs[i].first;
		return ret;
	}
	friend segment operator&(segment a, segment b)
	{
		vector<pair<double, double> > ret;
		int apos = 0, bpos = 0;
		while(apos < a.segs.size() && bpos < b.segs.size())
		{
			pair<T, T>& A = a.segs[apos];
			pair<T, T>& B = b.segs[bpos];
			if(A.second < B.first) { apos++; continue; }
			if(B.second < A.first) { bpos++; continue; }
			ret.push_back(pair<T, T>(max(A.first, B.first), min(A.second, B.second)));
			if(A.second < B.second) { apos++; continue; }
			else { bpos++; continue; }
		}
		return segment(ret);
	}
	friend segment operator|(segment a, segment b)
	{
		vector<pair<T, T> > ret;
		typename vector<pair<T, T> >::iterator ita = a.segs.begin(), itb = b.segs.begin();
		while(ita != a.segs.end() || itb != b.segs.end())
		{
			typename vector<pair<T, T> >::iterator* it;
			if(ita == a.segs.end())
				it = &itb;
			else if(itb == b.segs.end())
				it = &ita;
			else
				it = ita->first < itb->first ? &ita : &itb;
			
			if(ret.size() && ret.back().second >= (*it)->first)
				ret.back().second = max(ret.back().second, (*it)->second);
			else
				ret.push_back(**it);
			
			++(*it);
		}
		return segment(ret);
	}
	friend ostream& operator<<(ostream& os, segment a)
	{
		for(int i = 0; i < a.segs.size(); i++)
			cout << (i > 0 ? " " : "") << "(" << a.segs[i].first << "," << a.segs[i].second << ")";
		return os;
	}
};

double d(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double dabs(double x) { return x >= 0 ? x : -x; }

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<double> x(n), y(n), r(n);
		for(int i = 0; i < n; i++)
			cin >> x[i] >> y[i] >> r[i];
		double ans = 0;
		for(int i = 0; i < n; i++)
		{
			segment<double> removed;
			for(int j = 0; j < n; j++)
			{
				if(i == j) continue;
				double dist = d(x[i], y[i], x[j], y[j]);
				if(r[i]+r[j] <= dist) continue;
				if(r[i]-r[j] >= dist) continue;
				if(r[j]-r[i] >= dist) { removed = segment<double>(-M_PI, M_PI); break; }
				double width = acos((r[i]*r[i] + dist*dist - r[j]*r[j]) / (2 * r[i] * dist));
				double rad = acos((x[i]-x[j]) / dist) * (y[i]<y[j] ? 1 : -1);
				segment<double> cut;
				for(int i = -1; i <= 1; i++)
					cut = cut | segment<double>(rad-width+2*M_PI*i, rad+width+2*M_PI*i);
				cut = cut & segment<double>(-M_PI, M_PI);
				removed = removed | cut;
			}
			ans += (2*M_PI - removed.size()) * r[i];
		}
		printf("%.12f\n", ans);
	}
	return 0;
}
