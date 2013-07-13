#include <iostream>
using namespace std;

int main()
{
	const char rule[6][5] = {{'a','b','c','d','e'}, {'f','g','h','i','j'}, {'k','l','m','n','o'},
		{'p','q','r','s','t'}, {'u','v','w','x','y'}, {'z','.','?','!',' '}};
	
	string input;
	while(cin >> input)
	{
		if(input.length() % 2 == 1)
		{
			cout << "NA" << endl;
			continue;
		}
		string output;
		while(input.length())
		{
			if(input[0]-'1' < 0 || input[0]-'1' > 5 || input[1]-'1' < 0 || input[1]-'1' > 4)
			{
				output = "NA";
				break;
			}
			output += rule[input[0]-'1'][input[1]-'1'];
			input = input.substr(2);
		}
		cout << output << endl;
	}
	return 0;
}