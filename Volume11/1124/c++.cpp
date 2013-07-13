#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, Q;
	while(cin >> N >> Q, N)
	{
		int nod[100] = {};
		for(int i = 0; i < N; i++)
		{
			int num; cin >> num;
			while(num--)
			{
				int day; cin >> day;
				nod[day]++;
			}
		}
		
		int ans = 0;
		for(int i = 99; i >= 1; i--)
			if(nod[i] >= Q)
				ans = i, Q = nod[i];
		
		cout << ans << endl;
	}
	return 0;
}
