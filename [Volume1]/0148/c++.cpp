#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n) printf("3C%02d\n", (n-1) % 39+1);
	return 0;
}