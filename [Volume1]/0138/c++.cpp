#include <iostream>
using namespace std;

int main()
{
	double t_3rd[3] = {1e10, 1e10};
	int n_3rd[3];
	for(int k = 0; k < 3; k++)
	{
		double t[5] = {1e10, 1e10, 1e10, 1e10};
		int n[5];
		for(int i = 0; i < 8; i++)
		{
			int number;
			double time;
			cin >> number >> time;
			for(int j = 3; j >= 0; j--)
			{
				if(t[j] > time)
				{
					t[j+1] = t[j];
					n[j+1] = n[j];
					t[j] = time;
					n[j] = number;
				}
				else break;
			}
		}
		printf("%d %.2f\n%d %.2f\n", n[0], t[0], n[1], t[1]);
		for(int i = 2; i <= 3; i++)
		{
			for(int j = 1; j >= 0; j--)
			{
				if(t_3rd[j] > t[i])
				{
					t_3rd[j+1] = t_3rd[j];
					n_3rd[j+1] = n_3rd[j];
					t_3rd[j] = t[i];
					n_3rd[j] = n[i];
				}
				else break;
			}
		}
	}
	printf("%d %.2f\n%d %.2f\n", n_3rd[0], t_3rd[0], n_3rd[1], t_3rd[1]);
	return 0;
}