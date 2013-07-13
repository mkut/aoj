#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int separate(string& str)
{
	int ret = 0;
	while(str[ret] == ' ') ret++;
	str = str.substr(ret);
	return ret;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		string LF; getline(cin, LF);
		map<string,string> parent;
		vector<string> current;
		for(int i = 0; i < n; i++)
		{
			string str; getline(cin, str);
			int num = separate(str);
			if(current.size() > num)
				current[num] = str;
			else
				current.push_back(str);
			
			if(num == 0)
				parent[str] = "";
			else
				parent[str] = current[num-1];
		}
		
		for(int i = 0; i < m; i++)
		{
			string A, rel, B;
			cin >> A >> LF >> LF >> rel >> LF >> B;
			bool ans = false;
			B = B.substr(0, B.length() - 1);
			
			if(rel == "child")
				ans = B == parent[A];
			else if(rel == "parent")
				ans = A == parent[B];
			else if(rel == "sibling")
				ans = parent[A] == parent[B];
			else if(rel == "descendant")
			{
				string cur = A;
				while((cur = parent[cur]) != "")
				{
					if(cur == B)
					{
						ans = true;
						break;
					}
				}
			}
			else if(rel == "ancestor")
			{
				string cur = B;
				while((cur = parent[cur]) != "")
				{
					if(cur == A)
					{
						ans = true;
						break;
					}
				}
			}
			
			cout << (ans ? "True" : "False") << endl;
		}
		cout << endl;
	}
	return 0;
}
