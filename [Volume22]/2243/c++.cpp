#include <iostream>
#include <algorithm>
using namespace std;

int pos(char c)
{
	return (c-'1')%3;
}

int main()
{
	string steps;
	while(cin >> steps, steps != "#")
	{
		int ans = steps.size();
		for(int t = 0; t < 2; t++)
		{
			bool left = t;
			int p = pos(steps[0]);
			int count = 0;
			for(int i = 1; i < steps.size(); i++)
			{
				int next_p = pos(steps[i]);
				if(left ? next_p < p : next_p > p)
					count++;
				else
					left = !left;
				p = next_p;
			}
			ans = min(ans, count);
		}
		cout << ans << endl;
	}
	return 0;
}
