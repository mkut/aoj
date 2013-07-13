#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int l;
	while(cin >> l, l != 0)
	{
		int n, m;
		cin >> n >> m;
		set<int> shop;
		shop.insert(0);
		shop.insert(l);
		for(int i = 0; i < n-1; i++)
		{
			int tmp; cin >> tmp;
			shop.insert(tmp);
		}
		
		int sum = 0;
		for(int i = 0; i < m; i++)
		{
			int customer; cin >> customer;
			set<int>::iterator it = shop.upper_bound(customer);
			int d = *it - customer;
			--it;
			d = min(d, customer - *it);
			sum += d;
		}
		
		cout << sum << endl;
	}
	return 0;
}
