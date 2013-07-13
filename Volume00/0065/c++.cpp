#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	map<int, int> trade;
	string input;
	while(getline(cin, input), input != "")
	{
		string snumber = "";
		for(int i = 0; i < input.length() && input[i] != ','; i++)
		{
			snumber += input[i];
		}
		trade[atoi(snumber.c_str())]--;
	}
	while(getline(cin, input))
	{
		string snumber;
		for(int i = 0; i < input.length() && input[i] != ','; i++)
		{
			snumber += input[i];
		}
		if(trade[atoi(snumber.c_str())] > 0) trade[atoi(snumber.c_str())]++;
		if(trade[atoi(snumber.c_str())] < 0) trade[atoi(snumber.c_str())] = 1 - trade[atoi(snumber.c_str())];
	}
	//sort(trade.begin(). trade.end(), map<int, int>::key_comp());
	for(map<int, int>::iterator it = trade.begin(); it != trade.end(); it++)
	{
		if(it->second <= 0) continue;
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}