#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> cubic, tetra;
	for(int i = 0; i*i*i <= 151200; i++)
		cubic.push_back(i*i*i);
	for(int i = 0; i*(i+1)*(i+2)/6 <= 151200; i++)
		tetra.push_back(i*(i+1)*(i+2)/6);
	
	int n;
	while(cin >> n, n)
	{
		int ans = 0;
		for(int i = 0; i < cubic.size(); i++)
			for(int j = 0; j < tetra.size(); j++)
				if(cubic[i] + tetra[j] <= n)
					ans = max(ans, cubic[i] + tetra[j]);
		cout << ans << endl;
	}
	return 0;
}
