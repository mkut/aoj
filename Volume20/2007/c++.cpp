#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	bool first = true;
	while(cin >> n, n != 0)
	{
		if(!first)
			cout << endl;
		first = false;
		int n10, n50, n100, n500;
		cin >> n10 >> n50 >> n100 >> n500;
		int money = n10 * 10 + n50 * 50 + n100 * 100 + n500 * 500 - n;
		int m10 = money % 50 / 10;
		int m50 = money % 100 / 50;
		int m100 = money % 500 / 100;
		int m500 = money / 500;
		if(m10 < n10)
			cout << 10 << " " << n10 - m10 << endl;
		if(m50 < n50)
			cout << 50 << " " << n50 - m50 << endl;
		if(m100 < n100)
			cout << 100 << " " << n100 - m100 << endl;
		if(m500 < n500)
			cout << 500 << " " << n500 - m500 << endl;
	}
	return 0;
}
