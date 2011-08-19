#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long size(string str)
{
	unsigned long long r = 0;
	unsigned long long num = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		else if(num == 0)
			r++;
		else if(str[i] == '(')
		{
			int nest = 1;
			string s = "";
			while(nest > 0)
			{
				i++;
				if(str[i] == '(')
					nest++;
				else if(str[i] == ')')
					nest--;
				if(nest > 0) s += str[i];
			}
			r += num*size(s);
			num = 0;
		}
		else
		{
			r += num;
			num = 0;
		}
	}
	return r;
}

char expand(string str, int index)
{
	unsigned long long num = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		else if(num == 0)
		{
			if(index == 0)
				return str[i];
			index--;
		}
		else if(str[i] == '(')
		{
			int nest = 1;
			string s = "";
			while(nest > 0)
			{
				i++;
				if(str[i] == '(')
					nest++;
				else if(str[i] == ')')
					nest--;
				if(nest > 0) s += str[i];
			}
			unsigned long long _size = size(s);
			if(index / num < _size)
				return expand(s, index % _size);
			index -= _size*num;
			num = 0;
		}
		else
		{
			if(num > index)
				return str[i];
			index -= num;
			num = 0;
		}
	}
	return '0';
}

int main()
{
	string str;
	int index;
	while(cin >> str >> index, str != "0")
	{
		cout << expand(str, index) << endl;
	}
	return 0;
}
