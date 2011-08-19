#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int seq[5000];
		for(int i = 0; i < n; i++) cin >> seq[i];
		
		int ans = 0;
		int max = 0;
		int part = 0;
		int _max = seq[0];
		for(int i = 0; i < n; i++)
		{
			_max = seq[i] > _max ? seq[i] : _max;
			part += seq[i];
			if(max + part < 0)
			{
				ans = max > ans ? max : ans;
				max = 0;
				part = 0;
			}
			if(part > 0)
			{
				max += part;
				part = 0;
			}
		}
		ans = max > ans ? max : ans;
		cout << (ans == 0 ? _max : ans) << endl;
	}
	
	return 0;
}