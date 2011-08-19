#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, p;
	while(cin >> n >> p, n != 0)
	{
		vector<int> stone(n);
		int center = p;
		int person = 0;
		while(true)
		{
			if(center > 0)
			{
				center--;
				if(++stone[person] == p)
					break;
			}
			else
			{
				center = stone[person];
				stone[person] = 0;
			}
			if(++person == n)
				person = 0;
		}
		cout << person << endl;
	}
	return 0;
}
