#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

vector<string> split(string str, char delim){
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

set<string> solve(string name, map<string, set<string> >& ms)
{
	set<string> ret;
	if(!ms.count(name)) { ret.insert(name); return ret; }
	for(set<string>::iterator it = ms[name].begin(); it != ms[name].end(); ++it)
	{
		set<string> tmp = solve(*it, ms);
		ret.insert(tmp.begin(), tmp.end());
	}
	ms[name].clear();
	return ret;
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		map<string, set<string> > members;
		string fgroup;
		for(int i = 0; i < n; i++)
		{
			string input; cin >> input; input = input.substr(0, input.length() - 1);
			vector<string> spl1 = split(input, ':');
			vector<string> spl2 = split(spl1[1], ',');
			members[spl1[0]].insert(spl2.begin(), spl2.end());
			if(i == 0) fgroup = spl1[0];
		}
		
		int ans = solve(fgroup, members).size();
		cout << ans << endl;
	}
	return 0;
}
