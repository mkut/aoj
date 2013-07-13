#include <iostream>
#include <map>
using namespace std;

string small(string str)
{
	string ret = "";
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			ret += str[i]+'a'-'A';
		}
		else
		{
			ret += str[i];
		}
	}
	return ret;
}

int main()
{
	map<string, int> nword;
	string word;
	
	while(cin >> word)
	{
		nword[small(word)]++;
	}
	
	string wmode, wlong;
	int num = 0;
	int length = 0;
	for(map<string, int>::iterator it = nword.begin(); it != nword.end(); it++)
	{
		if(it->second > num)
		{
			num = it->second;
			wmode = it->first;
		}
		if(it->first.length() > length)
		{
			length = it->first.length();
			wlong = it->first;
		}
	}
	
	cout << wmode << " " << wlong << endl;
	return 0;
}