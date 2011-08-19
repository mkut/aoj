#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int d(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int N, X, Y; cin >> N >> X >> Y;
		int cx, cy; cin >> cx >> cy;
		vector<int> x(N), y(N), cooltime(N);
		for(int i = 0; i < N; i++)
			cin >> x[i] >> y[i];
		vector<vector<char> > linked(N, vector<char>(N));
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				linked[i][j] = d(x[i], y[i], x[j], y[j]) <= 50*50 ? 1 : 0;
		
		int ans = 0;
		set<int> prev;
		vector<char> done(N);
		for(int i = 0; i < N; i++)
			if(d(x[i], y[i], cx, cy) <= 10*10)
				prev.insert(prev.end(), i);
		while(!prev.empty())
		{
			ans += X;
			for(int i = 0; i < N; i++)
				cooltime[i] -= X;
			
			set<int> next;
			for(set<int>::iterator it = prev.begin(); it != prev.end(); it++)
			{
				int cur = *it;
				done[cur] = true;
				cooltime[cur] = Y;
			}
			for(set<int>::iterator it = prev.begin(); it != prev.end(); it++)
			{
				int cur = *it;
				for(int i = 0; i < N; i++)
				{
					if(cooltime[i] < 0 && linked[cur][i])
					{
						if(done[i])
							goto loopout;
						next.insert(i);
					}
				}
			}
			prev = next;
		}
		cout << ans << endl;
		continue;
loopout:
		cout << "You're always welcome!" << endl;
	}
	return 0;
}
