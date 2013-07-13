#include <iostream>
using namespace std;

string caesar(string str, int dif)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = (str[i]-'a'+dif)%26 + 'a';
		}
	}
	return str;
}

bool valid(string str)
{
	if(str.find("the") != string::npos) return true;
	if(str.find("this") != string::npos) return true;
	if(str.find("that") != string::npos) return true;
	return false;
}

int main()
{
	string input;
	while(getline(cin, input))
	{
		for(int i = 0; i < 26; i++)
		{
			if(valid(caesar(input, i)))
			{
				cout << caesar(input,i) << endl;
			}
		}
	}
	return 0;
}