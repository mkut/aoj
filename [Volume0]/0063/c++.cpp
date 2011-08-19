#include <iostream>
using namespace std;

int main()
{
	string input;
	int count = 0;
	while(getline(cin, input))
	{
		for(int i = 0; 2*i <= input.length(); i++)
		{
			if(input[i] != input[input.length()-1-i])
			{
				count--;
				break;
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}