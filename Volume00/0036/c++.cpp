#include <iostream>
using namespace std;

int main()
{
	int map[8];
	while(cin >> map[0])
	{
		for(int i = 1; i < 8; i++)
		{
			cin >> map[i];
		}
		
		for(int i = 0; i < 8; i++)
		{
			if(map[i] == 0) continue;
			
			if(map[i] % 1111 == 0)
			{
				cout << "C" << endl;
				break;
			}
			if(map[i] % 11 == 0)
			{
				if(map[i] == map[i+1])
				{
					cout << "A" << endl;
					break;
				}
				if(map[i] == map[i+1] * 10)
				{
					cout << "E" << endl;
					break;
				}
				if(map[i] * 10 == map[i+1])
				{
					cout << "G" << endl;
					break;
				}
			}
			if(map[i] == map[i+1])
			{
				cout << "B" << endl;
				break;
			}
			if(map[i] * 11 == map[i+1])
			{
				cout << "D" << endl;
				break;
			}
			cout << "F" << endl;
			break;
		}
	}
	return 0;
}