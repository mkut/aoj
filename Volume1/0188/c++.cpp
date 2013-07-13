#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> vi(n);
		for(int i = 0; i < n; i++)
			cin >> vi[i];
		
		int num;
		cin >> num;
		
		int begin = 0, end = vi.size()-1;
		for(int i = 1; ; i++)
		{
			if(vi[(begin+end)/2] == num)
			{
				cout << i << endl;
				break;
			}
			if(vi[(begin+end)/2] > num)
				end = (begin+end)/2 - 1;
			else
				begin = (begin+end)/2 + 1;
			if(begin > end)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
