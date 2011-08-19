#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		string str;
		cin >> str;
		;
		while(n--)
		{
			char prev = str[0];
			int count = 1;
			ostringstream oss;
			for(int i = 1; i < str.length(); i++)
			{
				if(prev == str[i])
				{
					count++;
				}
				else
				{
					oss << count << prev;
					prev = str[i];
					count = 1;
				}
			}
			oss << count << prev;
			str = oss.str();
		}
		cout << str << endl;
	}
	return 0;
}