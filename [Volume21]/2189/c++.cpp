#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string str;
		cin >> str;
		int sum = 0;
		for(int i = 0; i < str.length(); i++)
			sum += str[i] - '0';
		
		cout << ((((sum-1)/9+str.length())%2) ? "Audrey" : "Fabre") << " wins.\n";
	}
	return 0;
}
