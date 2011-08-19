#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> Point;

int d(Point p, int X, int Y)
{
	int ax = p.first*2 + p.second%2, ay = p.second;
	int bx = X*2 + Y%2, by = Y;
	int A = abs(ay - by);
	int B = abs((ax+ay) - (bx+by))/2;
	int C = abs((ax-ay) - (bx-by))/2;
	return max(A, max(B, C));
}

int main()
{
	int m, n;
	while(cin >> m >> n, m)
	{
		int s; cin >> s;
		vector<Point> stores(s);
		for(int i = 0; i < s; i++)
		{
			int x, y; cin >> x >> y;
			stores[i] = Point(x-1, y-1);
		}
		int t; cin >> t;
		int ans = 0;
		for(int i = 0; i < t; i++)
		{
			int x, y; cin >> x >> y;
			Point pos(x-1, y-1);
			int count = 0;
			for(int X = 0; X < m; X++)
				for(int Y = 0; Y < n; Y++)
				{
					bool near = true;
					for(int k = 0; k < s; k++)
						if(d(stores[k], X, Y) <= d(pos, X, Y))
							near = false;
					if(near)
						count++;
				}
			ans = max(ans, count);
		}
		cout << ans << endl;
	}
	return 0;
}
