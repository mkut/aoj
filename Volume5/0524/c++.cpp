#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> x(n), y(n);
		for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
		
		int m;
		cin >> m;
		vector<int> X(m), Y(m);
		for(int j = 0; j < m; j++) cin >> X[j] >> Y[j];
		
		for(int j = 0; j < m; j++)
		{
			bool ok = true;
			for(int i = 1; i < n; i++)
			{
				bool check = false;
				for(int j2 = 0; j2 < m; j2++)
				{
					if(X[j2] - X[j] == x[i] - x[0] && Y[j2] - Y[j] == y[i] - y[0])
					{
						check = true;
						break;
					}
				}
				if(!check)
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				cout <<  X[j] - x[0] << " " << Y[j] - y[0] << endl;
			}
		}
		
	}
	return 0;
}