#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;

vector<string> split(string str, char delim)
{
	vector<string> ret;
	for(string::size_type pos = str.find(delim); pos != string::npos; pos = str.find(',')){
		ret.push_back(str.substr(0, pos));
		str = str.substr(pos+1);
	}
	if(str.length() > 0){
		ret.push_back(str);
	}
	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	int cost[21][21];
	memset(cost, -1, sizeof(cost));
	
	int start, goal, receive;
	
	for(int i = 0; i < m; i++)
	{
		string input;
		cin >> input;
		vector<string> paths = split(input, ',');
		
		int a = atoi(paths[0].c_str());
		int b = atoi(paths[1].c_str());
		int c = atoi(paths[2].c_str());
		int d = atoi(paths[3].c_str());
		cost[a][b] = c;
		cost[b][a] = d;
	}
	for(int i = 0; i < 1; i++)
	{
		string input;
		cin >> input;
		vector<string> values = split(input, ',');
		start = atoi(values[0].c_str());
		goal = atoi(values[1].c_str());
		receive = atoi(values[2].c_str()) - atoi(values[3].c_str());
	}
	
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(cost[i][k] == -1 || cost[k][j] == -1) continue;
				if(cost[i][j] == -1) cost[i][j] = cost[i][k] + cost[k][j];
				else cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}
	
	cout << receive - cost[start][goal] - cost[goal][start] << endl;
	
	return 0;
}