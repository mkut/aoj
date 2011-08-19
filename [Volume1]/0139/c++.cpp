#include <iostream>
using namespace std;

string typeA(int length)
{
	string r = ">'";
	for(int i = 0; i < (length-4)/2; i++) r += '=';
	r += '#';
	for(int i = 0; i < (length-4)/2; i++) r += '=';
	r += '~';
	return r;
}
string typeB(int length)
{
	string r = ">^";
	for(int i = 0; i < (length-4)/2; i++) r += "Q=";
	r += "~~";
	return r;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string input;
		cin >> input;
		if(input.length() < 6) cout << "NA" << endl;
		else if(input == typeA(input.length())) cout << 'A' << endl;
		else if(input == typeB(input.length())) cout << 'B' << endl;
		else cout << "NA" << endl;
	}
	return 0;
}