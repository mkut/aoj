#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int h, m, s;
	while(cin >> h >> m >> s)
	{
		int begin = h*3600 + m*60 + s;
		cin >> h >> m >> s;
		int end = h*3600 + m*60 + s;
		cout << (end- begin)/3600 << " " << (end-begin)/60%60 << " " << (end-begin)%60 << endl;
	}
	return 0;
}