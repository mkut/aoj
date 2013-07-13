#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int q[9][9];
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cin >> q[i][j];
			}
		}
		
		bool ans[9][9] = {};
		
		for(int i = 0; i < 9; i++)
		{
			bool chk[10] = {};
			int pos[10] = {};
			for(int j = 0; j < 9; j++)
			{
				if(chk[q[i][j]])
				{
					ans[i][j] = true;
					ans[i][pos[q[i][j]]] = true;
					continue;
				}
				chk[q[i][j]] = true;
				pos[q[i][j]] = j;
			}
		}
		for(int j = 0; j < 9; j++)
		{
			bool chk[10] = {};
			int pos[10] = {};
			for(int i = 0; i < 9; i++)
			{
				if(chk[q[i][j]])
				{
					ans[i][j] = true;
					ans[pos[q[i][j]]][j] = true;
					continue;
				}
				chk[q[i][j]] = true;
				pos[q[i][j]] = i;
			}
		}
		for(int i = 0; i < 9; i++)
		{
			bool chk[10] = {};
			int pos[10] = {};
			for(int j = 0; j < 9; j++)
			{
				if(chk[q[i%3*3+j%3][i/3*3+j/3]])
				{
					ans[i%3*3+j%3][i/3*3+j/3] = true;
					ans[i%3*3+pos[q[i%3*3+j%3][i/3*3+j/3]]%3][i/3*3+pos[q[i%3*3+j%3][i/3*3+j/3]]/3] = true;
					continue;
				}
				chk[q[i%3*3+j%3][i/3*3+j/3]] = true;
				pos[q[i%3*3+j%3][i/3*3+j/3]] = j;
			}
		}
		
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				cout << (ans[i][j] ? "*" : " ") << q[i][j];
			}
			cout << endl;
		}
		if(n != 0)cout << endl;
	}
	return 0;
}