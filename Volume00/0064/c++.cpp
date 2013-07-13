#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	string input;
	while(getline(cin, input))
	{
		int cur = 0;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] >= '0' && input[i] <= '9')
			{
				cur = cur * 10 + input[i] - '0';
			}
			else
			{
				sum += cur;
				cur = 0;
			}
		}
		sum +=cur;
	}
	
	cout << sum << endl;
	
	return 0;
}