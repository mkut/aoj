#include <iostream>
using namespace std;

int main()
{
	string input;
	char cur = 'A';
	while(getline(cin, input))
	{
		if(input[0] == cur) cur = input[2];
		else if(input[2] == cur) cur = input[0];
	}
	cout << cur << endl;
}