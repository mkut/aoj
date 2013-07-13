#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void reset(vector<vector<int> >& lab)
{
	for(int i = 0; i < lab.size(); i++)
		for(int j = 0; j < lab[i].size(); j++)
			if(lab[i][j] == -2)
				lab[i][j] = -1;
}

int draw(vector<vector<int> >& lab, int x, int y, int cur, priority_queue<int>& Q)
{
	//cout << "(" << x << "," << y << ")" << endl;
	if(x < 0 || x >= lab.size() || y < 0 || y >= lab[0].size()) return 0;
	if(lab[x][y] > cur) Q.push(-lab[x][y]);
	if(lab[x][y] > cur || lab[x][y] == -2) return 0;
	
	int dx[] = {0,0,1,-1}, dy[] = {-1,1,0,0};
	
	int ret = lab[x][y] == -1 ? 0 : 1;
	lab[x][y] = -2;
	
	for(int i = 0; i < 4; i++)
		ret += draw(lab, x+dx[i], y+dy[i], cur, Q);
	return ret;
}

void solve(vector<vector<int> >& lab, vector<int>& rank, vector<int>& room, int x, int y)
{
	rank.push_back(0);
	room.push_back(0);
	priority_queue<int> Q;
	Q.push(-lab[x][y]);
	int cur = 0;
	while(!Q.empty())
	{
		while(!Q.empty() && cur == -Q.top()) Q.pop();
		if(Q.empty()) break;
		cur = -Q.top(); Q.pop();
		//cout << "[" << cur << "]" << endl;
		rank.push_back(cur);
		room.push_back(room.back() + draw(lab, x, y, cur, Q));
		reset(lab);
	}
}

int main()
{
	int R;
	while(cin >> R, R)
	{
		vector<vector<int> > lab[2];
		int elev_x[2], elev_y[2];
		for(int i = 0; i < 2; i++)
		{
			int W, H, X, Y;
			cin >> W >> H >> X >> Y;
			X--; Y--;
			elev_x[i] = Y; elev_y[i] = X;
			lab[i] = vector<vector<int> >(H, vector<int>(W));
			for(int j = 0; j < H; j++)
				for(int k = 0; k < W; k++)
					cin >> lab[i][j][k];
		}
		
		vector<int> rank[2], room[2];
		
		for(int i = 0; i < 2; i++)
			solve(lab[i], rank[i], room[i], elev_x[i], elev_y[i]);
		
		/*
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < rank[i].size(); j++)
				cout << "(" << rank[i][j] << "," << room[i][j] << ") ";
			cout << endl;
		}
		*/
		
		int cur[2];
		int ans = 10000000; 
		
		for(cur[0] = rank[0].size()-1, cur[1] = 0; cur[0] >= 0; cur[0]--)
		{
			while(room[0][cur[0]] + room[1][cur[1]] < R) cur[1]++;
			ans = min(ans, rank[0][cur[0]] + rank[1][cur[1]]);
		}
		cout << ans << endl;
	}
	return 0;
}
