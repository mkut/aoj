#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	while(cin >> N >> M, N != 0)
	{
		vector<vector<int> > LOG(M);
		vector<int> usePC(M);
		int r;
		cin >> r;
		for(int i = 0; i < r; i++)
		{
			int t, n, m, s;
			cin >> t >> n >> m >> s;
			m--;
			if(s == 1)
			{
				if(usePC[m]++ == 0)
					LOG[m].push_back(t);
			}
			else
			{
				if(--usePC[m] == 0)
					LOG[m].push_back(t);
			}
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; i++)
		{
			int ts, te, m, sum = 0;
			cin >> ts >> te >> m;
			m--;
			for(int i = 0; i < LOG[m].size(); i+=2)
				sum += max(0, min(LOG[m][i+1], te) - max(LOG[m][i], ts));
			cout << sum << endl;
		}
	}
	return 0;
}
