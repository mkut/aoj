#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int height[100];
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> height[i];
		}
		
		int max_up = 0, max_down = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(height[i+1] - height[i] > 0)
			{
				max_up = max(max_up, height[i+1] - height[i]);
			}
			else
			{
				max_down = max(max_down, height[i] - height[i+1]);
			}
		}
		printf("%d %d\n", max_up, max_down);
	}
	return 0;
}