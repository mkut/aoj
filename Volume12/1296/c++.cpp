#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

string replace(string str, string from, string to){
	for(string::size_type pos = str.find(from); pos != string::npos; pos = str.find(from, to.length() + pos)){
		str.replace(pos, from.length(), to);
	}
	return str;
}

int solve(vector<string>& from, vector<string>& to, string start, string& end)
{
	if(start == end) return 0;
	if(start.length() >= end.length()) return 1<<20;
	int ret = 1<<20;
	for(int i = 0; i < from.size(); i++)
	{
		string next = replace(start, from[i], to[i]);
		if(start != next)
		{
			int res = solve(from, to, next, end);
			ret = min(ret, res + 1);
		}
	}
	return ret;
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		vector<string> from(n), to(n);
		for(int i = 0; i < n; i++)
			cin >> from[i] >> to[i];
		
		string start, end; cin >> start >> end;
		int ans = solve(from, to, start, end);
		cout << (ans == 1<<20 ? -1 : ans) << endl;
	}
	return 0;
}
