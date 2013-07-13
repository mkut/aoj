#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int h[5];
	while(cin >> h[0], h[0] != 0)
	{
		for(int i = 1; i < 5; i++)
			cin >> h[i];
		
		bool t[3] = {};
		for(int i = 0; i < 5; i++)
			t[--h[i]] = true;
		
		int num = 0;
		for(int i = 0; i < 3; i++)
			if(t[i])
				num++;
		
		if(num != 2)
			for(int i = 0; i < 5; i++)
				cout << 3 << endl;
		else
			for(int i = 0; i < 3; i++)
				if(!t[i])
					for(int j = 0; j < 5; j++)
						cout << (h[j] + 3 - i) % 3 << endl;
	}
	return 0;
}
