#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != -1)
	{
		stringstream ss;
		while(n != 0)
		{
			ss << n%4;
			n /= 4;
		}
		string ans;
		ss >> ans;
		if(ans == "") ans = "0";
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	return 0;
}