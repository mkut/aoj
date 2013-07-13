#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, h;
	while(cin >> n >> h, n != 0)
	{
		vector<int> exist;
		for(int i = 0; i < h; i++)
		{
			string str;
			int v1, v2;
			cin >> str >> v1 >>v2;
			if(str == "xy")
			{
				for(int i = 1; i <= n; i++)
				{
					exist.push_back(v1+v2*512+i*512*512);
				}
			}
			if(str == "xz")
			{
				for(int i = 1; i <= n; i++)
				{
					exist.push_back(v1+i*512+v2*512*512);
				}
			}
			if(str == "yz")
			{
				for(int i = 1; i <= n; i++)
				{
					exist.push_back(i+v1*512+v2*512*512);
				}
			}
		}
		sort(exist.begin(), exist.end());
		exist.erase(unique(exist.begin(), exist.end()), exist.end());
		
		cout << n*n*n - exist.size() << endl;
	}
	return 0;
}