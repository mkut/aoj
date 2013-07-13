#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int gcd(int x, int y)
{
	return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int x, int y)
{
	return x / gcd(x, y) * y;
}

string shorten(string str)
{
	int d = str.length() / 2;
	for(int i = 1; i < str.length() / 2; i++)
	{
		if(str.substr(i*2,2) != "00")
		{
			d = gcd(i, d);
		}
	}
	string ret = "";
	for(int i = 0; i*d < str.length() / 2; i++)
	{
		ret += str.substr(i*d*2,2);
	}
	return ret;
}
string mix(string str1, string str2)
{
	if(str1 == "Too complex." || str2 == "Too complex.") return "Too complex.";
	
	str1 = shorten(str1);
	str2 = shorten(str2);
	int _lcm = lcm(str1.length()/2, str2.length()/2);
	if(_lcm > 1024) return "Too complex.";
	
	ostringstream stream;
	stream << setfill('0') << hex << uppercase;
	for(int i = 0; i < _lcm; i++)
	{
		int  itmp = 0;
		if(i % (_lcm / (str1.length()/2)) == 0) itmp |= strtol(str1.substr(i / (_lcm / (str1.length()/2)) * 2, 2).c_str(), NULL, 16);
		if(i % (_lcm / (str2.length()/2)) == 0) itmp |= strtol(str2.substr(i / (_lcm / (str2.length()/2)) * 2, 2).c_str(), NULL, 16);
		stream << setw(2) << itmp;
	}
	return stream.str();
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string ans = "00";
		for(int i = 0; i < n; i++)
		{
			string input;
			cin >> input;
			ans = mix(ans, input);
		}
		cout << ans << endl;
	}
	return 0;
}