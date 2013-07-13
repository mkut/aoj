#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int kupc[4] = {};
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == 'K') kupc[0]++;
		else if(str[i] == 'U') kupc[1]++;
		else if(str[i] == 'P') kupc[2]++;
		else if(str[i] == 'C') kupc[3]++;
	}
	int ans = kupc[0];
	for(int i = 0; i < 4; i++)
		ans = min(ans, kupc[i]);
	cout << ans << endl;
	return 0;
}
