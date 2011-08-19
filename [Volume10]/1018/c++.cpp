#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> lst(n);
		for(int i = 0; i < n; i++) cin >> lst[i];
		sort(lst.begin(), lst.end());
		
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum += lst[i]*(n-i);
		}
		cout << sum << endl;
	}
	return 0;
}