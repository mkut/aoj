#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int time = 0;
	for(int i = 0; i < 4; i++)
	{
		int tmp; cin >> tmp;
		time += tmp;
	}
	cout << time / 60 << endl << time % 60 << endl;
	return 0;
}
