#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#include <map>

int main()
{
	string left = "qwertasdfgzxcvb";
	string right = "yuiophjklnm";
	map<char, int> lr;
	for(int i = 0; i < left.length(); i++)
		lr[left[i]] = 1;
	for(int i = 0; i < right.length(); i++)
		lr[right[i]] = -1;

	string str;
	while(cin >> str, str != "#")
	{
		int hand = lr[str[0]];
		int ans = 0;
		for(int i = 1; i < str.length(); i++)
		{
			if(hand != lr[str[i]])
				ans++;
			hand = lr[str[i]];
		}
		cout << ans << endl;
	}
}

