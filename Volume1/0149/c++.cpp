#include <iostream>
using namespace std;

int main()
{
	const double st[3] = {0.2, 0.6, 1.1};
	
	int numL[4] = {}, numR[4] = {};
	double left, right;
	while(cin >> left >> right)
	{
		int rankL = 0, rankR =0;
		for(int i = 0; i < 3; i++)
		{
			if(st[i] <= left) rankL++;
			if(st[i] <= right) rankR++;
		}
		numL[rankL]++;
		numR[rankR]++;
	}
	
	for(int i = 3; i >= 0; i--)
	{
		cout << numL[i] << " " << numR[i] << endl;
	}
	return 0;
}