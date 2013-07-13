#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<string> grid;
		for(int i = 0; i < n; i++)
		{
			string tmp; cin >> tmp;
			grid.push_back(tmp);
		}
		int _max = 0;
		for(int i = 0; i < n; i++)
		{
			int cur = 0;
			for(int j = 0; j < n; j++)
			{
				if(grid[i][j] == '1') _max = max(_max, ++cur);
				else cur = 0;
			}
		}
		for(int i = 0; i < n; i++)
		{
			int cur = 0;
			for(int j = 0; j < n; j++)
			{
				if(grid[j][i] == '1') _max = max(_max, ++cur);
				else cur = 0;
			}
		}
		for(int i = 0; i <= (n-1)*2; i++)
		{
			int cur = 0;
			for(int j = 0; j < n; j++)
			{
				if(i-j < 0 || i-j >= n) continue;
				if(grid[j][i-j] == '1') _max = max(_max, ++cur);
				else cur = 0;
			}
		}
		for(int i = 1-n; i < n; i++)
		{
			int cur = 0;
			for(int j = 0; j < n; j++)
			{
				if(i+j < 0 || i+j >= n) continue;
				if(grid[j][i+j] == '1') _max = max(_max, ++cur);
				else cur = 0;
			}
		}
		cout << _max << endl;
	}
	return 0;
}