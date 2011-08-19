#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct Road
{
	int D, P;
	Road(int d, int p) : D(d), P(p) {}
	
	bool operator<(const Road& a) const
	{
		return P > a.P;
	}
};

int main()
{
	int N, M;
	while(cin >> N >> M, N)
	{
		vector<Road> roads(N, Road(0,0));
		for(int i = 0; i < N; i++)
		{
			int D, P; cin >> D >> P;
			roads[i] = Road(D, P);
		}
		sort(roads.begin(), roads.end());
		int ans = 0;
		for(int i = 0; i < roads.size(); i++)
		{
			ans += max(0, roads[i].D - M) * roads[i].P;
			M -= roads[i].D;
			M = max(0, M);
		}
		cout << ans << endl;
	}
	return 0;
}
