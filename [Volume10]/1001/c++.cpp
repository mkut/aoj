#include <iostream>
#include <map>
using namespace std;

pair<string, string> devide(string str)
{
	string left, right;
	int blacount = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '(') blacount++;
		else if(str[i] == ')') blacount--;
		else if(blacount == 1 && str[i] == ',')
		{
			left = str.substr(1, i-1);
			right = str.substr(i+1, str.length()-i-2);
		}
	}
	return pair<string, string>(left, right);
}

string _inter(string a, string b)
{
	if(a == "" || b == "") return "";
	return '(' + _inter(devide(a).first, devide(b).first) + "," + _inter(devide(a).second, devide(b).second) + ')';
}

string _union(string a, string b)
{
	if(a == "") return b;
	if(b == "") return a;
	return '(' + _union(devide(a).first, devide(b).first) + "," + _union(devide(a).second, devide(b).second) + ')';
}

int main()
{
	char type;
	string a,b;
	while(cin >> type >> a >> b)
	{
		if(type == 'i') cout << _inter(a, b) << endl;
		if(type == 'u') cout << _union(a, b) << endl;
	}
	return 0;
}