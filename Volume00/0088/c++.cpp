#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<char, string> sign;
	map<string, char> unsign;
	sign[' '] = "101";     sign['\'']= "000000";  sign[','] = "000011";  sign['-'] = "10010001";
	sign['.'] = "010001";  sign['?'] = "000001";  sign['A'] = "100101";  sign['B'] = "10011010";
	sign['C'] = "0101";    sign['D'] = "0001";    sign['E'] = "110";     sign['F'] = "01001";
	sign['G'] = "10011011";sign['H'] = "010000";  sign['I'] = "0111";    sign['J'] = "10011000";
	sign['K'] = "0110";    sign['L'] = "00100";   sign['M'] = "10011001";sign['N'] = "10011110";
	sign['O'] = "00101";   sign['P'] = "111";     sign['Q'] = "10011111";sign['R'] = "1000";
	sign['S'] = "00110";   sign['T'] = "00111";   sign['U'] = "10011100";sign['V'] = "10011101";
	sign['W'] = "000010";  sign['X'] = "10010010";sign['Y'] = "10010011";sign['Z'] = "10010000";
	unsign["00000"] = 'A'; unsign["00001"] = 'B'; unsign["00010"] = 'C'; unsign["00011"] = 'D';
	unsign["00100"] = 'E'; unsign["00101"] = 'F'; unsign["00110"] = 'G'; unsign["00111"] = 'H';
	unsign["01000"] = 'I'; unsign["01001"] = 'J'; unsign["01010"] = 'K'; unsign["01011"] = 'L';
	unsign["01100"] = 'M'; unsign["01101"] = 'N'; unsign["01110"] = 'O'; unsign["01111"] = 'P';
	unsign["10000"] = 'Q'; unsign["10001"] = 'R'; unsign["10010"] = 'S'; unsign["10011"] = 'T';
	unsign["10100"] = 'U'; unsign["10101"] = 'V'; unsign["10110"] = 'W'; unsign["10111"] = 'X';
	unsign["11000"] = 'Y'; unsign["11001"] = 'Z'; unsign["11010"] = ' '; unsign["11011"] = '.';
	unsign["11100"] = ','; unsign["11101"] = '-'; unsign["11110"] = '\'';unsign["11111"] = '?';
	
	string input;
	while(getline(cin ,input))
	{
		string code = "";
		for(int i = 0; i < input.length(); i++)
		{
			code += sign[input[i]];
		}
		while(code.length() % 5 != 0) code += "0";
		for(string::size_type pos = 0; pos < code.length(); pos++)
		{
			code.replace(pos, 5, 1, unsign[code.substr(pos, 5)]);
		}
		cout << code << endl;
	}
	return 0;
}