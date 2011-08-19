#include <iostream>
using namespace std;

int main()
{
	char c;
	while(c = cin.get(), !cin.eof())
	{
		if(c >= 'a' && c <= 'z')
		{
			c += 'A'-'a';
		}
		cout << c;
	}
	return 0;
}