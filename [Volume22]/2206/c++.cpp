#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void fall(vector<string>& map)
{
	for(int j = 0; j < 6; j++)
	{
		int count = 11;
		for(int i = 11; i >= 0; i--)
		{
			if(map[i][j] != '.')
			{
				map[count--][j] = map[i][j];
			}
		}
		while(count >= 0)
		{
			map[count][j] = '.';
			count--;
		}
	}
}

void erase(int i, int j, char c, vector<string>& map)
{
	if(i < 0 || i >= 12 || j < 0 || j >= 6)
		return;
	
	if(map[i][j] == 'O')
	{
		map[i][j] = '.';
		return;
	}
	
	if(map[i][j] != c)
		return;
	
	map[i][j] = '.';
	erase(i+1, j, c, map);
	erase(i-1, j, c, map);
	erase(i, j+1, c, map);
	erase(i, j-1, c, map);
}

int search(int i, int j, char c, vector<string>& map)
{
	if(i < 0 || i >= 12 || j < 0 || j >= 6)
		return 0;
	
	if(map[i][j] == 'O')
		return 0;
	
	if(map[i][j] != c)
		return 0;
	
	map[i][j] = '.';
	int ret = 1;
	ret += search(i+1, j, c, map);
	ret += search(i-1, j, c, map);
	ret += search(i, j+1, c, map);
	ret += search(i, j-1, c, map);
	return ret;
}

bool solve(vector<string>& ori_map)
{
	bool cntn = false;
	vector<string> map = ori_map;
	for(int i = 0; i < 12; i++)
		for(int j = 0; j < 6; j++)
			if(map[i][j] != '.')
				if(search(i, j, map[i][j], map) >= 4)
				{
					erase(i, j, ori_map[i][j], ori_map);
					cntn = true;
				}
	
	/*
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 6; j++)
			cout << ori_map[i][j];
		cout << endl;
	}
	cout << endl;
	*/
	
	fall(ori_map);
	return cntn;
}

int main()
{
	int n; cin >> n;
	while(n--)
	{
		vector<string> map(12);
		
		for(int i = 0; i < 12; i++)
			cin >> map[i];
		
		int ans = 0;
		while(solve(map))
			ans++;
		
		cout << ans << endl;
	}
	return 0;
}
