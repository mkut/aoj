#include <iostream>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
	{
		int joi = 0, ioi = 0;
		for(int i = 0; i < str.length()-2; i++)
		{
			if(str.substr(i,3) == "JOI") joi++;
			if(str.substr(i,3) == "IOI") ioi++;
		}
		cout << joi << endl << ioi << endl;
	}
	return 0;
}