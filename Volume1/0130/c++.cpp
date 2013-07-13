#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string input;
		cin >> input;
		
		string ans = "";
		int pos = 0;
		while(true)
		{
			if(pos >= (int)ans.length()) ans = ans + input[0];
			if(pos == -1){ ans = input[0] + ans; pos++; }
			if(input.length() < 4) break;
			if(input[1] == '-') pos++;
			else pos--;
			input = input.substr(3);
		}
		cout << ans << endl;
	}
	return 0;
}