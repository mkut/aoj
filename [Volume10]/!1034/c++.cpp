#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> Point;
typedef vector<int> Line;
typedef vector<Line> Puzzle;

class solver
{
  private:
	Puzzle pzl;
	vector<Point> starts;
	
  public:
	solver(Puzzle pzl, vector<Point> starts)
	{
		this->pzl = pzl;
		this->starts = starts;
	}
	
	bool solve()
	{
		return _solve(pzl, 0, starts[0].first, starts[0].second);
	}
	
  private:
	bool _solve(Puzzle pzl, int startno, int x, int y)
	{
		//d(pzl);
		if(pzl[x][y] == 0)
		{
			if(startno == starts.size()-1) return true;
			return _solve(pzl, startno+1, starts[startno+1].first, starts[startno+1].second);
		}
		if(pzl[x][y] > 0)
		{
			return false;
		}
		int cx[4] = {-1,1,0,0}, cy[4] = {0,0,-1,1};
		for(int i = 0; i < 4; i++)
		{
			if(pzl[x+cx[i]][y+cy[i]] > 0)
			{
				pzl[x+cx[i]][y+cy[i]] += pzl[x][y];
				if(_solve(pzl, startno, x+cx[i], y+cy[i])) return true;
				pzl[x+cx[i]][y+cy[i]] -= pzl[x][y];
			}
		}
		return false;
	}
	
	void d(Puzzle p)
	{
		for(int i = 0; i < p.size(); i++)
		{
			for(int j = 0; j < p[i].size(); j++)
			{
				printf("%5d", p[i][j]);
			}
			cout << endl;
		}
	}
	
	bool cmp(Point a, Point b)
	{
		return pzl[a.first][a.second] < pzl[b.first][b.second];
	}
};

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		Puzzle pzl;
		vector<Point> starts;
		Line edge(n+2); for(int i = 0; i < n+2; i++) edge[i] = -100;
		pzl.push_back(edge);
		for(int i = 1; i <= n; i++)
		{
			pzl.push_back(Line(n+2));
			pzl[i][0] = -100; pzl[i][n+1] = -100;
			for(int j = 1; j <= n; j++)
			{
				cin >> pzl[i][j];
				if(pzl[i][j] < 0) starts.push_back(Point(i,j));
			}
		}
		pzl.push_back(edge);
		
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				sum += pzl[i][j];
			}
		}
		if(sum != 0) {cout << "NO" << endl; continue;}
		
		solver prob(pzl, starts);
		cout << (prob.solve() ? "YES" : "NO") << endl;
	}
	return 0;
}