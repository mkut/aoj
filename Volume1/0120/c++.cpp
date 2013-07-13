#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

bool solve_min(vector<int> remain, int prev1, int prev2, int prev3, double size)
{
	if(size < prev1) return false;
	if(remain.size() == 0) return true;
	
	for(int i = 0; i < remain.size(); i++)
	{
		if(i > 0 && remain[i] == remain[i-1]) continue;
		if(prev3 == 0 || prev1 > prev2 == prev3 > remain[i] || prev1 == prev2 || prev3 == remain[i])
		{
			vector<int> next = remain;
			next.erase(next.begin()+i);
			if(solve_min(next, remain[i], prev1, prev2, size - 2*sqrt(prev1*remain[i]))) return true;
		}
	}
	return false;
}

bool solve(vector<int> remain, int size)
{
	for(int i = 0; i < remain.size(); i++)
	{
		if(i > 0 && remain[i] == remain[i-1]) continue;
		vector<int> next = remain;
		next.erase(next.begin()+i);
		if(solve_min(next, remain[i], 0, 0, (double)size - remain[i])) return true;
	}
	return false;
}

vector<string> split(string str, char delim)
{
	vector<string> ret;
	for(string::size_type pos = str.find(delim); pos != string::npos; pos = str.find(delim)){
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
	string dataset;
	while(getline(cin, dataset))
	{
		vector<string> set = split(dataset, ' ');
		int size = atoi(set[0].c_str());
		vector<int> r;
		for(int i = 1; i < set.size(); i++) r.push_back(atoi(set[i].c_str()));
		
		sort(r.begin(), r.end());
		cout << (solve(r, size) ? "OK" : "NA") << endl;
	}
	return 0;
}