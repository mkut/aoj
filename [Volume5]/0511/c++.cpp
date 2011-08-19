#include <iostream>
using namespace std;

int main()
{
	bool attend[30] = {};
	for(int i = 0; i < 28; i++)
	{
		int tmp; cin >> tmp;
		attend[tmp-1] = true;
	}
	for(int i = 0; i < 30; i++)
	{
		if(!attend[i]) cout << i+1 << endl;
	}
	return 0;
}