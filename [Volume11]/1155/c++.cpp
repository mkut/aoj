#include <iostream>
#include <algorithm>
using namespace std;

struct TriBool
{
	char val;
	TriBool()
	{
		val = 0;
	}
	TriBool(int i)
	{
		val = i;
	}
	TriBool operator-()
	{
		return TriBool(2-val);
	}
	TriBool operator*(TriBool b)
	{
		return TriBool(min(val, b.val));
	}
	TriBool operator+(TriBool b)
	{
		return TriBool(max(val, b.val));
	}
	bool operator==(TriBool b)
	{
		return val == b.val;
	}
};

TriBool calc(string str)
{
	if(str[0] == '-')
	{
		return -calc(str.substr(1));
	}
	else if(str[0] == '(')
	{
		int nest = 0;
		for(int i = 1; i < str.size(); i++)
		{
			if(str[i] == '(')
				nest++;
			if(str[i] == ')')
				nest--;
			if(str[i] == '+' && nest == 0)
				return calc(str.substr(1, i-1)) + calc(str.substr(i+1, str.size()-i-2));
			if(str[i] == '*' && nest == 0)
				return calc(str.substr(1, i-1)) * calc(str.substr(i+1, str.size()-i-2));
		}
	}
	else
	{
		return TriBool(str[0] - '0');
	}
}

int main()
{
	string str;
	while(cin >> str, str != ".")
	{
		int ans = 0;
		for(int p = 0; p < 3; p++)
			for(int q = 0; q < 3; q++)
				for(int r = 0; r < 3; r++)
				{
					string tmp = str;
					for(int i = 0; i < tmp.size(); i++)
					{
						if(tmp[i] == 'P')
							tmp[i] = p + '0';
						else if(tmp[i] == 'Q')
							tmp[i] = q + '0';
						else if(tmp[i] == 'R')
							tmp[i] = r + '0';
					}
					if(calc(tmp) == TriBool(2))
						ans++;
				}
		cout << ans << endl;
	}
	return 0;
}
