#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int rect = 0;
	int dia = 0;
	char str1[100], str2[100], str3[100];
	while(cin.getline(str1, 100, ','), cin.getline(str2, 100, ','), cin.getline(str3, 100, '\n'))
	{
		int a = atoi(str1);
		int b = atoi(str2);
		int c = atoi(str3);
		if(a*a + b*b == c*c) rect++;
		if(a == b) dia++;
	}
	
	cout << rect << endl << dia << endl;
	return 0;
}