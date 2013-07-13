#include <iostream>
#include <map>
using namespace std;

int main()
{
	int size;
	while(cin >> size, size != 0)
	{
		map<int, int> count;
		bool finished = false;
		for(int i = 0; i < size; i++)
		{
			int tmp;
			cin >> tmp;
			count[tmp]++;
		}
		for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
		{
			if(it->second > size/2)
			{
				cout << it->first << endl;
				finished = true;
				break;
			}
		}
		if(!finished) cout << "NO COLOR" << endl;
	}
	return 0;
}