#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int student[100][100];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin >> student[i][j];
			}
		}
		
		bool finished = false;
		for(int i = 0; i < n; i++)
		{
			int minpos = 0;
			for(int j = 1; j < n; j++)
			{
				if(student[i][j] < student[i][minpos]) minpos = j;
			}
			bool ok = true;
			for(int j = 0; j < n; j++)
			{
				if(student[j][minpos] > student[i][minpos]) ok = false;
			}
			if(ok)
			{
				cout << student[i][minpos] << endl;
				finished = true;
				break;
			}
		}
		if(!finished) cout << 0 << endl;
	}
	return 0;
}