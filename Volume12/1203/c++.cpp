#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

string conv(string str)
{
	string ret = "";
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
			ret += str[i];
		else if(str[i] >= 'a' && str[i] <= 'z')
			ret += str[i] - 'a' + 'A';
	}
	return ret;
}
string solve1(string str, int pos, set<string>& ignore)
{
	int width = 1;
	for(; pos - width >= 0 && pos + width < str.length() && str[pos-width] == str[pos+width]; width++)
		ignore.insert(str.substr(pos-width+1, width*2-1));
	return str.substr(pos-width+1, width*2-1);
}
string solve2(string str, int pos, set<string>& ignore)
{
	if(str[pos] != str[pos+1]) return "";
	int width = 1;
	for(; pos - width >= 0 && pos + width + 1 < str.length() && str[pos-width] == str[pos+width+1]; width++)
		ignore.insert(str.substr(pos-width+1, width*2));
	return str.substr(pos-width+1, width*2);
}

int main()
{
	string input;
	while(getline(cin, input))
	{
		input = conv(input);
		set<string> ans, ignore;
		for(int i = 0; i < input.length(); i++)
		{
			string tmp = solve1(input, i, ignore);
			if(tmp.length() >= 3)
				ans.insert(tmp);
			tmp = solve2(input, i, ignore);
			if(tmp.length() >= 3)
				ans.insert(tmp);
		}
		bool first = true;
		for(set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
			if(!ignore.count(*it))
				cout << (first ? "" : " ") << *it, first = false;
		cout << endl;
	}
	return 0;
}
