#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		bool first = true;
		for(int i = 0; i < 10; i++)
		{
			if(n & (1 << i))
			{
				cout << (first ? "" : " ") << (1 << i);
				first = false;
			}
		}
		cout << endl;
	}
	return 0;
}