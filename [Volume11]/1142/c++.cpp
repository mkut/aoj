#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string str;
		cin >> str;
		vector<string> ans;
		for(int i = 1; i < str.length(); i++)
		{
			string f, b;
			f = str.substr(0, i);
			b = str.substr(i);
			if(count(ans.begin(), ans.end(), f+b) == 0)
				ans.push_back(f+b);
			if(count(ans.begin(), ans.end(), b+f) == 0)
				ans.push_back(b+f);
			reverse(f.begin(), f.end());
			if(count(ans.begin(), ans.end(), f+b) == 0)
				ans.push_back(f+b);
			if(count(ans.begin(), ans.end(), b+f) == 0)
				ans.push_back(b+f);
			reverse(b.begin(), b.end());
			if(count(ans.begin(), ans.end(), f+b) == 0)
				ans.push_back(f+b);
			if(count(ans.begin(), ans.end(), b+f) == 0)
				ans.push_back(b+f);
			reverse(f.begin(), f.end());
			if(count(ans.begin(), ans.end(), f+b) == 0)
				ans.push_back(f+b);
			if(count(ans.begin(), ans.end(), b+f) == 0)
				ans.push_back(b+f);
		}
		cout << ans.size() << endl;
	}
	return 0;
}
