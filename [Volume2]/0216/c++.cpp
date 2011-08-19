#include <iostream>
#include <algorithm>
using namespace std;

int calc(int w)
{
	int ret = 1150;
	ret += max(w-10, 0) * 125;
	ret += max(w-20, 0) * 15;
	ret += max(w-30, 0) * 20;
	return ret;
}

int main()
{
	int w;
	while(cin >> w, ~w)
		cout << 4280 - calc(w) << endl;
	return 0;
}
