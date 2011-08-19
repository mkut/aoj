#include <iostream>
#include <algorithm>
#include <bitset>
#include <set>
using namespace std;

#define SIZE 10000008
typedef bitset<SIZE> bits;

int main()
{
	int prev[3] = {};
	int p[4] = {0,1,2,0};
	bits notprime;
	set<int> ans;
	for(int i = 2; i < SIZE; i++)
		if(!notprime[i])
		{
			for(int j = i+i; j < SIZE; j+= i)
				notprime[j] = true;
			if(prev[p[0]] + 8 == i && prev[p[1]] + 6 == i && prev[p[2]] + 2 == i)
				ans.insert(-i);
			prev[p[0]] = i;
			for(int j = 0; j < 3; j++)
				p[j] = p[j+1];
			p[3] = p[0];
		}
	
	int n;
	while(cin >> n, n)
		cout << -*ans.lower_bound(-n) << endl;
	return 0;
}
