#include <iostream>
using namespace std;

int main()
{
	int guest[8];
	int patern[8][8] = {{1,2,1,2,1,4,1,4},{1,2,1,4,1,4,1,2},{1,4,1,2,1,2,1,4},{1,4,1,4,1,2,1,2},{2,1,2,1,4,1,4,1},{2,1,4,1,4,1,2,1},{4,1,2,1,2,1,4,1},{4,1,4,1,2,1,2,1}};
	
	while(cin >> guest[0])
	{
		for(int i = 1; i < 8; i++) cin >> guest[i];
		
		int sad = 1e9;
		int ans;
		for(int i = 0; i < 8; i++)
		{
			int cursad = 0;
			for(int j = 0; j < 8; j++)
			{
				cursad += guest[j] > patern[i][j] ? guest[j] - patern[i][j] : 0;
			}
			if(cursad < sad)
			{
				sad = cursad;
				ans = i;
			}
		}
		for(int i = 0; i < 8; i++)
		{
			cout << patern[ans][i] << (i == 7 ? "" : " ");
		}
		cout << endl;
	}
	return 0;
}