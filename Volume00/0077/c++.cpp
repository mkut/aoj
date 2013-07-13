#include <iostream>
using namespace std;

int main()
{
	string input;
	while(cin >> input)
	{
		for(string::size_type pos = input.find("@"); pos != string::npos; pos = input.find("@", pos))
		{
			string to = "";
			for(int i = 0; i < input[pos+1] - '0'; i++)
			{
				to += input[pos+2];
			}
			input.replace(pos, 3, to);
		}
		cout << input << endl;
	}
	return 0;
}