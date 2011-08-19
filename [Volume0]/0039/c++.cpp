#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<char, int> roman;
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
	roman['\0'] = 0;
	
	string input;
	while(cin >> input)
	{
		int ans = 0;
		for(int i = 0; i < input.length(); i++)
		{
			if(roman[input[i]] * 5 == roman[input[i+1]] || roman[input[i]] * 10 == roman[input[i+1]])
			{
				ans -= roman[input[i]];
			}
			else
			{
				ans += roman[input[i]];
			}
		}
		cout << ans << endl;
	}
	return 0;
}