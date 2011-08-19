#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
	string strt; getline(cin,strt);
	int t = atoi(strt.c_str());
	while(t--)
	{
		string buf; getline(cin, buf);
		string strn; getline(cin, strn);
		int n = atoi(strn.c_str());
		
		int cur = 0;
		while(n--)
		{
			string com;
			getline(cin, com);
			if(com[0] == 'f' && com[8] == 'c')
			{
				if(cur < buf.size())
					cur++;
			}
			else if(com[0] == 'b' && com[9] == 'c')
			{
				if(cur > 0)
					cur--;
			}
			else if(com[0] == 'f' && com[8] == 'w')
			{
				while(cur < buf.size() && buf[cur] == ' ')
					cur++;
				while(cur < buf.size() && buf[cur] != ' ')
					cur++;
			}
			else if(com[0] == 'b' && com[9] == 'w')
			{
				while(cur > 0 && buf[cur-1] == ' ')
					cur--;
				while(cur > 0 && buf[cur-1] != ' ')
					cur--;
			}
			else if(com[0] == 'd' && com[7] == 'c')
			{
				if(cur != buf.size())
					buf = buf.substr(0, cur) + buf.substr(cur+1);
			}
			else if(com[0] == 'd' && com[7] == 'w')
			{
				int end = cur;
				bool found = false;
				while(end < buf.size() && buf[end] == ' ')
					end++;
				while(end < buf.size() && buf[end] != ' ')
				{
					end++;
					found = true;
				}
				if(found)
					buf = buf.substr(0, cur) + buf.substr(end);
			}
			else
			{
				int begin = com.find("\"") + 1;
				int end = com.find("\"", begin);
				buf = buf.substr(0, cur) + com.substr(begin, end-begin) + buf.substr(cur);
				cur += end-begin;
			}
			//cout << "[" << com << "]" << endl;
			//cout << buf.substr(0, cur) << "^" << buf.substr(cur) << endl;
		}
		
		cout << buf.substr(0, cur) << "^" << buf.substr(cur) << endl;
	}
	return 0;
}
