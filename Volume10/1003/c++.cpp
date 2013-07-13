#include <iostream>
using namespace std;

void output(char c, int num)
{
	if(c == -1) return;
	const char out[9][8] = {{'\'',',','.','!','?'}, {'a','b','c','A','B','C'}, {'d','e','f','D','E','F'},
			{'g','h','i','G','H','I'}, {'j','k','l','J','K','L'}, {'m','n','o','M','N','O'},
			{'p','q','r','s','P','Q','R','S'}, {'t','u','v','T','U','V'}, {'w','x','y','z','W','X','Y','Z'}};
	const int outnum[9] = {5,6,6,6,6,6,8,6,8};
	if(c == '0')
	{
		for(int i = 0; i < num-1; i++) cout << " ";
		return;
	}
	cout << out[c-'1'][(num-1) % outnum[c-'1']];
}

int main()
{
	string input;
	while(cin >> input)
	{
		char prev = -1;
		int prevnum = 0;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] == prev)
			{
				prevnum++;
			}
			else
			{
				output(prev, prevnum);
				prev = input[i];
				prevnum = 1;
			}
		}
		output(prev, prevnum);
		cout << endl;
	}
	return 0;
}