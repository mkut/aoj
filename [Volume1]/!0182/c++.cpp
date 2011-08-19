#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> beaker(n);
		for(int i = 0; i < n; i++)
		{
			cin >> beaker[i];
		}
	}
	
	return 0;
}