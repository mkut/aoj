#include <iostream>
using namespace std;

string replace(string str, string from, string to)
{
	for(string::size_type pos = str.find(from); pos != string::npos; pos = str.find(from, to.length() + pos))
	{
		str.replace(pos, from.length(), to);
	}
	return str;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(100, '\n');
	while(n--)
	{
		string str;
		getline(cin, str);
		cout << replace(str, "Hoshino", "Hoshina") << endl;
	}
	return 0;
}