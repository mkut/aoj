#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int _map[11] = {};
		for(int i = 1; i <= 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				int tmp;
				cin >> tmp;
				_map[i] = _map[i]*2+tmp;
			}
			_map[i] *= 2;
		}
		
		for(int i = 0; i < (1<<10); i++)
		{
			int ans[11] = {0,i*2};
			for(int j = 2; j <= 10; j++)
			{
				for(int k = 1; k <= 10; k++)
				{
					ans[j] |= (_map[j-1] >> k & 1 ^ ans[j-1] >> k & 1 ^ ans[j-1] >> k-1 & 1 ^ ans[j-1] >> k+1 & 1 ^ ans[j-2] >> k & 1) << k;
				}
			}
			bool ok = true;
			for(int k = 1; k <= 10; k++)
			{
				if((_map[10] >> k & 1 ^ ans[10] >> k & 1 ^ ans[10] >> k-1 & 1 ^ ans[10] >> k+1 & 1 ^ ans[9] >> k & 1) != 0)
				{
					ok =false;
					break;
				}
			}
			if(ok)
			{
				for(int j = 1; j <= 10; j++)
				{
					for(int k = 10; k >= 1; k--)
					{
						cout << (ans[j] >> k & 1) << (k == 1 ? "" : " ");
					}
					cout << endl;
				}
				break;
			}
		}
	}
	return 0;
}