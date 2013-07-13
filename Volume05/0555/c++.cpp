#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	string key; cin >> key;
	int N; cin >> N;
	int ans = 0;
	while(N--)
	{
		string str; cin >> str;
		for(int i = 0; i < 10; i++)
		{
			bool ok = true;
			for(int j = 0; j < key.length(); j++)
			{
				if(str[(i+j)%10] != key[j])
					ok = false;
			}
			if(ok) { ans++; break; }
		}
	}
	cout << ans << endl;
	return 0;
}
