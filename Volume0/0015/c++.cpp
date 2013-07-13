#include <iostream>
#include <algorithm>
using namespace std;

string add(string str1, string str2)
{
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string ret;
	for(int i = 0; i < str1.length() || i < str2.length(); i++)
	{
		ret += '0' + (i < str1.length() ? str1[i] - '0' : 0) + (i < str2.length() ? str2[i] - '0' : 0);
	}
	for(int i = 0; i < ret.length(); i++)
	{
		if(ret[i] > '9')
		{
			ret[i] -= 10;
			if(i == ret.length() - 1)
			{
				ret += '1';
			}
			else
			{
				ret[i+1]++;
			}
		}
	}
	reverse(ret.begin(), ret.end());
	return ret.length() > 80 ? "overflow" : ret;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		
		cout << add(str1, str2) << endl;
	}
	return 0;
}