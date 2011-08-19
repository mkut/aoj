#include <iostream>
using namespace std;

int main()
{
	long long input;
	while(cin >> input)
	{
		int number[10];
		for(int i = 0; i < 10; i++)
		{
			number[i] = input % 10;
			input /= 10;
		}
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9 - i; j++)
			{
				number[j] = (number[j] + number[j+1]) % 10;
			}
		}
		cout << number[0] << endl;
	}
	return 0;
}