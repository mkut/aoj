#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		bool finished = false;
		int m, atari, d;
		string line[31];
		cin >> m >> atari >> d;
		for(int i = 1; i <= d; i++)
		{
			cin >> line[i];
			line[i] = '0' + line[i] + '0';
		}
		
		int ataripos[31], selectpos[31];
		ataripos[d] = atari;
		selectpos[0] = m;
		for(int i = d; i > 0; i--)
		{
			if(line[i][ataripos[i]] == '1') ataripos[i-1] = ataripos[i] + 1;
			else if(line[i][ataripos[i]-1] == '1') ataripos[i-1] = ataripos[i] - 1;
			else ataripos[i-1] = ataripos[i];
		}
		for(int i = 0; i < d; i++)
		{
			if(line[i+1][selectpos[i]] == '1') selectpos[i+1] = selectpos[i] + 1;
			else if(line[i+1][selectpos[i]-1] == '1') selectpos[i+1] = selectpos[i] - 1;
			else selectpos[i+1] = selectpos[i];
		}
		
		if(selectpos[0] == ataripos[0])
		{
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < d; i++)
		{
			if(abs(selectpos[i]-ataripos[i]) == 1)
			{
				int mid = (selectpos[i]+ataripos[i])/2;
				if(line[i+1][mid-1] == '0' && line[i+1][mid] == '0' && line[i+1][mid+1] == '0')
				{
					cout << i+1 << " " << mid << endl;
					finished = true;
					break;
				}
			}
		}
		if(!finished) cout << 1 << endl;
	}
	return 0;
}