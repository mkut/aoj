#include <iostream>
#include <string>
#include <map>
using namespace std;

string code(string str)
{
	string ret = "";
	map<char, string> rule;
	rule['A'] = "00000"; rule['B'] = "00001";  rule['C'] = "00010";  rule['D'] = "00011";
	rule['E'] = "00100"; rule['F'] = "00101";  rule['G'] = "00110";  rule['H'] = "00111";
	rule['I'] = "01000"; rule['J'] = "01001";  rule['K'] = "01010";  rule['L'] = "01011";
	rule['M'] = "01100"; rule['N'] = "01101";  rule['O'] = "01110";  rule['P'] = "01111";
	rule['Q'] = "10000"; rule['R'] = "10001";  rule['S'] = "10010";  rule['T'] = "10011";
	rule['U'] = "10100"; rule['V'] = "10101";  rule['W'] = "10110";  rule['X'] = "10111";
	rule['Y'] = "11000"; rule['Z'] = "11001";  rule[' '] = "11010";  rule['.'] = "11011";
	rule[','] = "11100"; rule['-'] = "11101";  rule['\'']= "11110";  rule['?'] = "11111";
	for(int i = 0; i < str.length(); i++)
	{
		ret += rule[str[i]];
	}
	return ret;
}
string decode(string str)
{
	string ret = "";
	map<string, char> rule;
	rule["101"]      = ' '; rule["000000"]   ='\''; rule["000011"]   = ','; rule["10010001"] = '-';
	rule["010001"]   = '.'; rule["000001"]   = '?'; rule["100101"]   = 'A'; rule["10011010"] = 'B';
	rule["0101"]     = 'C'; rule["0001"]     = 'D'; rule["110"]      = 'E'; rule["01001"]    = 'F';
	rule["10011011"] = 'G'; rule["010000"]   = 'H'; rule["0111"]     = 'I'; rule["10011000"] = 'J';
	rule["0110"]     = 'K'; rule["00100"]    = 'L'; rule["10011001"] = 'M'; rule["10011110"] = 'N';
	rule["00101"]    = 'O'; rule["111"]      = 'P'; rule["10011111"] = 'Q'; rule["1000"]     = 'R';
	rule["00110"]    = 'S'; rule["00111"]    = 'T'; rule["10011100"] = 'U'; rule["10011101"] = 'V';
	rule["000010"]   = 'W'; rule["10010010"] = 'X'; rule["10010011"] = 'Y'; rule["10010000"] = 'Z';
	for(int i = 1; i < 9 ; i++)
	{
		if(rule.count(str.substr(0, i)) > 0)
		{
			ret += rule[str.substr(0, i)];
			str =str.substr(i);
			i = 0;
		}
	}
	return ret;
}

int main()
{
	string str;
	while(getline(cin, str))
	{
		cout << decode(code(str)) << endl;
	}
}