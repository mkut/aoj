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
	string input;
	getline(cin, input);
	input = replace(input, "apple", "<apple>");
	input = replace(input, "peach", "apple");
	input = replace(input, "<apple>", "peach");
	cout << input << endl;
	return 0;
}