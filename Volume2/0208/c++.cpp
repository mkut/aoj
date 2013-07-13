#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		char str[16];
		sprintf(str, "%o", n);
		for(int i = 0; i < 16; i++)
		{
			if(str[i] == '\0')
				break;
			if(str[i] >= '4')
				str[i]++;
			if(str[i] >= '6')
				str[i]++;
		}
		cout << str << endl;
	}
	return 0;
}
