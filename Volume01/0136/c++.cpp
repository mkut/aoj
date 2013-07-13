#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int rank[6] = {};
	int ranklim[5] = {165, 170, 175, 180, 185};
	while(n--)
	{
		double height;
		cin >> height;
		
		bool finished = false;
		for(int i = 0; i < 5; i++)
		{
			if(height < ranklim[i])
			{
				rank[i]++;
				finished = true;
				break;
			}
		}
		if(!finished)
		{
			rank[5]++;
		}
	}
	
	for(int i = 0; i < 6; i++)
	{
		cout << i+1 << ":";
		while(rank[i]--) cout << "*";
		cout << endl;
	}
	return 0;
}