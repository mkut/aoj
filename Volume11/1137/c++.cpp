#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int cnv(string str)
{
	int r = 0;
	int mlt = 1;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= '2' && str[i] <= '9')
		{
			mlt = str[i] - '0';
		}
		else
		{
			int num;
			if(str[i] == 'm') num = 1000;
			else if(str[i] == 'c') num = 100;
			else if(str[i] == 'x') num = 10;
			else if(str[i] == 'i') num = 1;
			r += mlt * num;
			mlt = 1;
		}
	}
	return r;
}

string cnv(int num)
{
	ostringstream oss;
	char pref[] = {'i', 'x', 'c', 'm'};
	for(int i = 0; num != 0; i++)
	{
		if(num % 10 >= 1)
			oss << pref[i];
		if(num % 10 >= 2)
			oss << num%10;
		num /= 10;
	}
	string r = oss.str();
	reverse(r.begin(), r.end());
	return r;
}
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		cout << cnv(cnv(str1) + cnv(str2)) << endl;
	}
	return 0;
}
