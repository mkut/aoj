#include <iostream>
using namespace std;

int main()
{
	string name;
	int am, pm;
	while(cin >> name >> am >> pm)
	{
		printf("%s %d %d\n", name.c_str(), am+pm, am*200+pm*300);
	}
	return 0;
}