#include <iostream>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string word = "";
	bool first = true;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ' || str[i] == ',' || str[i] == '.')
		{
			if(word.length() >= 3 && word.length() <= 6)
			{
				cout << (first ? "" : " ") << word;
				first = false;
			}
			word = "";
		}
		else
		{
			word += str[i];
		}
	}
	
	cout << endl;
	return 0;
}