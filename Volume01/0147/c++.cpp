#include <iostream>
using namespace std;

int main()
{
	int seet[17] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int outtime[17] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int group = 0;
	int ans[100];
	for(int t = 0; group < 100; t++)
	{
		// go out
		for(int j = 0; j < 17; j++)
		{
			if(outtime[j] == t)
			{
				seet[j] = -1;
				outtime[j] = -1;
			}
		}
		
		// visit
		while(t >= group*5)
		{
			ans[group] = t - group*5;
			bool full = true;
			if(group % 5 != 1)
			{
				for(int j = 0; j + 2 <= 17; j++)
				{
					if(seet[j] ==-1 && seet[j+1] ==-1)
					{
						seet[j] = group;
						seet[j+1] = group;
						outtime[j] = t + 17*(group%2) + 3*(group%3) + 19;
						outtime[j+1] = t + 17*(group%2) + 3*(group%3) + 19;
						group++;
						full = false;
						break;
					}
				}
			}
			else
			{
				for(int j = 0; j + 5 <= 17; j++)
				{
					if(seet[j] ==-1 && seet[j+1] ==-1 && seet[j+2] ==-1 && seet[j+3] ==-1 && seet[j+4] ==-1)
					{
						seet[j] = group;
						seet[j+1] = group;
						seet[j+2] = group;
						seet[j+3] = group;
						seet[j+4] = group;
						outtime[j] = t + 17*(group%2) + 3*(group%3) + 19;
						outtime[j+1] = t + 17*(group%2) + 3*(group%3) + 19;
						outtime[j+2] = t + 17*(group%2) + 3*(group%3) + 19;
						outtime[j+3] = t + 17*(group%2) + 3*(group%3) + 19;
						outtime[j+4] = t + 17*(group%2) + 3*(group%3) + 19;
						group++;
						full = false;
						break;
					}
				}
			}
			if(full) break;
		}
	}
	
	int n;
	while(cin >> n) cout << ans[n] << endl;
	return 0;
}