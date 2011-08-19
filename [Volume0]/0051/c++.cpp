#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int input;
		int num[2][10] = {};
		int max = 0, min = 0;
		for(cin >> input; input != 0; input /= 10)
		{
			num[0][input % 10]++;
			num[1][input % 10]++;
		}
		for(int i = 9; i >= 0; i--)
		{
			if(num[0][i] > 0)
			{
				num[0][i]--;
				max = max * 10 + i;
				i++;
			}
		}
		for(int i = 0; i <= 9; i++)
		{
			if(num[1][i] > 0)
			{
				num[1][i]--;
				min = min * 10 + i;
				i--;
			}
		}
		//cout << max << endl << min << endl;
		cout << max - min << endl;
	}
	return 0;
}