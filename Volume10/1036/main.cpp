#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	string top, left, bottom;
	while(cin >> top >> left >> bottom, top != "-")
	{
		string right;
		char cur = left[0];
		left = left.substr(1);
		while(left != "" || top != "")
		{
			if(cur == bottom[0])
			{
				bottom = bottom.substr(1);
				if(top != "")
				{
					cur = top[0];
					top = top.substr(1);
				}
				else
				{
					cur = left[0];
					left = left.substr(1);
				}
			}
			else
			{
				right += cur;
				if(left != "")
				{
					cur = left[0];
					left = left.substr(1);
				}
				else
				{
					cur = top[0];
					top = top.substr(1);
				}
			}
		}
		right += cur;
		cout << right << endl;
	}
	return 0;
};
