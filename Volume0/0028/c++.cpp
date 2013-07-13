#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	map<int, int> data;
	vector<int> ans;
	int num = 0;
	
	int tmp;
	while(cin >> tmp)
	{
		if(data.find(tmp) != data.end())
		{
			(data.find(tmp)->second)++;
		}
		else
		{
			data.insert(pair<int, int>(tmp, 1));
		}
	}
	
	for(map<int, int>::iterator it = data.begin(); it != data.end(); it++)
	{
		if(it->second > num)
		{
			num = it->second;
			ans = vector<int>();
			ans.insert(ans.end(), it->first);
		}
		else if(it->second == num)
		{
			ans.insert(ans.end(), it->first);
		}
	}
	sort(ans.begin(), ans.end());
	
	for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
	{
		cout << (*it) <<endl;
	}
	
	return 0;
}