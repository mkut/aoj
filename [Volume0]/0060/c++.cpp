#include <iostream>
using namespace std;

int main()
{
	int c1, c2, c3;
	while(cin >> c1 >> c2 >> c3)
	{
		bool shown[11] = {};
		shown[c1] = true;
		shown[c2] = true;
		shown[c3] = true;
		
		int count = 0;
		for(int i = 1; i <= 10; i++)
		{
			if(c1 + c2 + i <= 20 && !shown[i])
			{
				count++;
			}
		}
		cout << (count > 3 ? "YES" : "NO") << endl;
	}
	return 0;
}