#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	string str;
	while(cin >> n >> m >> str, n != 0)
	{
		int ans = 0;
		for(int i = 0; i < m; i++)
		{
			if(str[i] == 'I')
			{
				int count = 0;
				while(str[i+1] == 'O' && str[i+2] == 'I')
				{
					count++;
					i+=2;
				}
				ans += max(0, count-n+1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
