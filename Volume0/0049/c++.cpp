#include <iostream>
using namespace std;

int main()
{
	string number, blood;
	int A = 0;
	int B = 0;
	int AB = 0;
	int O = 0;
	while(getline(cin, number, ','))
	{
		getline(cin,blood);
		if(blood == "A") A++;
		if(blood == "B") B++;
		if(blood == "AB") AB++;
		if(blood == "O") O++;
	}
	cout << A << endl << B <<endl << AB << endl << O << endl;
	return 0;
}