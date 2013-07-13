#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> part(1);
		
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			if(i % 2 == 0) // odd
			{
				if(part.size() % 2 == tmp)
					part.push_back(1);
				else
					part.back()++;
			}
			else // even
			{
				if(part.size() % 2 != tmp)
					part.back()++;
				else
				{
					if(part.size() == 1)
					{
						part.push_back(part[0] + 1);
						part[0] = 0;
					}
					else
					{
						part[part.size()-2] += part[part.size()-1] + 1;
						part.erase(part.end()-1);
					}
				}
			}
		}
		int sum = 0;
		for(int i = 0; i < part.size(); i += 2)
			sum += part[i];
		cout << sum << endl;
	}
	return 0;
}
