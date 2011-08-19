#include <iostream>
using namespace std;

int main()
{
	string g[3];
	while(cin >> g[0], g[0] != "0")
	{
		cin >> g[1] >> g[2];
		for(int k = 0; k < 3; k++)
		{
			int A = 0, B = 0;
			for(int i = 1; i < g[k].length(); i++)
			{
				if(g[k][i] == 'A') A++;
				else B++;
			}
			cout << (A>B ? A+1 : A) << " " << (B>A ? B+1 : B) << endl;
		}
	}
	return 0;
}