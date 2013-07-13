#include <iostream>
using namespace std;

int main()
{
	string input;
	cin >> input;
	for(int i = 0; i < input.length(); i++)
	{
		input[i] = (input[i] -'A'+23)%26+'A';
	}
	cout << input << endl;
	return 0;
}