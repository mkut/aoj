#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

vector<string> split(string str, string delim)
{
	vector<string> ret;
	for(string::size_type pos = str.find_first_of(delim); pos != string::npos; pos = str.find_first_of(delim))
	{
		if(pos > 0)
		{
			ret.push_back(str.substr(0, pos));
		}
		str = str.substr(pos+1);
	}
	if(str.length() > 0)
	{
		ret.push_back(str);
	}
	return ret;
}

int main()
{
	string input[100];
	int length = 0;
	for(; getline(cin, input[length]); length++);
	
	int map[100][60] = {};
	for(int i = 0; i < length; i++)
	{
		vector<string> words = split(input[i], ",");
		for(int j = 0; j < words.size(); j++)
		{
			map[i][j + max(0, i-length/2) + 1] = atoi(words[j].c_str());
		}
	}
	for(int i = 1; i < length; i++)
	{
		for(int j = 1; j <= i+1; j++)
		{
			map[i][j] += max(map[i-1][j], map[i-1][j-1]);
		}
	}
	cout << map[length-1][length/2+1] << endl;
	return 0;
}