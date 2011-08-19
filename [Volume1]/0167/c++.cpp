#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		int count = 0;
		int lst[100];
		for(int i = 0; i < n; i++)
		{
			cin >> lst[i];
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				if(lst[i] > lst[j]) count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}