#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 99999999;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main()
{
	int H, W, N; cin >> H >> W >> N;
	vector<string> view(H);
	for(int i = 0; i < H; i++) cin >> view[i];
	vector<int> xs(N+1), ys(N+1);
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			if(view[i][j] >= '1' && view[i][j] <= '9')
				xs[view[i][j] - '0'] = i, ys[view[i][j] - '0'] = j;
			else if(view[i][j] == 'S')
				xs[0] = i, ys[0] =j;
	
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		//cout << "[" << i << "]" << endl;
		vector<string> tmp = view;
		vector<pair<int,int> > prev;
		prev.push_back(pair<int,int>(xs[i], ys[i]));
		for(int step = 0; prev.size(); step++)
		{
			//cout << step << ":" << endl;
			vector<pair<int,int> > next;
			bool ok = false;
			for(int j = 0; j < prev.size(); j++)
			{
				int x = prev[j].first, y = prev[j].second;
				if(x < 0 || x >= H || y < 0 || y >= W) continue;
				if(tmp[x][y] == 'X') continue;
				//cout << x << "," << y << endl;
				if(x == xs[i+1] && y == ys[i+1]) { ok = true; ans += step; break; }
				tmp[x][y] = 'X';
				for(int k = 0; k < 4; k++)
					next.push_back(pair<int,int>(x+dx[k], y+dy[k]));
			}
			if(ok) break;
			prev = next;
		}
	}
	cout << ans << endl;
	return 0;
}
