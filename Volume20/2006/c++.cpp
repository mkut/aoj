#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string input;
		cin >> input;
		
		const char c[][5] = {{'.',',','!','?',' '},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
		const int m[] = {5,3,3,3,3,3,4,3,4};
		
		int ch = -1;
		int num = -1;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] == '0')
			{
				if(ch != -1)
				{
					cout << c[ch][num % m[ch]];
					ch = -1;
					num = -1;
				}
			}
			else
			{
				ch = input[i] - '1';
				num++;
			}
		}
		cout << endl;
	}
	return 0;
}
