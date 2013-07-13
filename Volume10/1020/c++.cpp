#include <iostream>
using namespace std;

int main()
{
	int n;
	char s, t, b;
	while(cin >> n, n != 0)
	{
		cin >> s >> t >> b;
		double rate[9] = {};
		rate[s-'A'] = 1;
		
		while(n--)
		{
			double next[9] = {};
			for(int i = 0; i < 9; i++)
			{
				if(i>=3 && i-3 != b-'A') next[i-3] += rate[i]/4;
				else next[i] += rate[i]/4;
				
				if(i<6 && i+3 != b-'A') next[i+3] += rate[i]/4;
				else next[i] += rate[i]/4;
				
				if(i%3!=0 && i-1 != b-'A') next[i-1] += rate[i]/4;
				else next[i] += rate[i]/4;
				
				if(i%3!=2 && i+1 != b-'A') next[i+1] += rate[i]/4;
				else next[i] += rate[i]/4;
			}
			for(int i = 0; i < 9; i++) rate[i] = next[i];
		}
		
		printf("%.8f\n", rate[t-'A']);
	}
	return 0;
}