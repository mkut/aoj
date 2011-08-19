#include <iostream>
using namespace std;

string conv(const string str, unsigned char* code)
{
	string ret = "";
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			ret += code[str[i] - 'a'] + 'a';
		}
		else
		{
			ret += str[i];
		}
	}
	return ret;
}

bool ok(const string str)
{
	int thisthat = 0;
	
	for(int i = 0; i < str.length(); i++)
	{
		if(thisthat == 0 && str[i] == 't') thisthat = 1;
		else if(thisthat == 1 && str[i] == 'h') thisthat = 2;
		else if(thisthat == 2 && str[i] == 'i') thisthat = 3;
		else if(thisthat == 2 && str[i] == 'a') thisthat = 4;
		else if(thisthat == 3 && str[i] == 's') thisthat = 5;
		else if(thisthat == 4 && str[i] == 't') thisthat = 5;
		else if(thisthat == 5 && str[i] == ' ') return true;
		else if(thisthat == 5) thisthat = 6;
		else if(str[i] == ' ') thisthat = 0;
		else thisthat = 6;
	}
	return thisthat == 5 ? true : false;
}

int main()
{
	unsigned char alpha[] = {1,3,5,7,9,11,15,17,19,21,23,25};
	unsigned char affine[12][26][26];
	
	for(unsigned char i = 0; i < 12; i++)
	{
		for(unsigned char j = 0; j < 26; j++)
		{
			for(unsigned char k = 0; k < 26; k++)
			{
				affine[i][j][(alpha[i] * k + j) % 26] = k;
			}
		}
	}
	
	int n;
	string str;
	cin >> n;
	getline(cin, str);
	while(n--)
	{
		getline(cin, str);
		for(int i = 0; i < 12; i++)
		{
			for(int j = 0; j < 26; j++)
			{
				if(ok(conv(str, affine[i][j])))
				{
					cout << conv(str, affine[i][j]) << endl;
				}
			}
		}
	}
	return 0;
}