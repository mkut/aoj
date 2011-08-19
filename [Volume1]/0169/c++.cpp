#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<string> split(string str, char delim)
{
	vector<string> ret;
	for(string::size_type pos = str.find(delim); pos != string::npos; pos = str.find(delim)){
		ret.push_back(str.substr(0, pos));
		str = str.substr(pos+1);
	}
	if(str.length() > 0){
		ret.push_back(str);
	}
	return ret;
}

int main()
{
	string input;
	while(getline(cin, input), input != "0")
	{
		vector<string> hands = split(input, ' ');
		int onenum = 0;
		int sum = 0;
		for(int i = 0; i < hands.size(); i++)
		{
			int tmp = atoi(hands[i].c_str());
			if(tmp == 1)
			{
				sum += 11;
				onenum++;
			}
			else if(tmp >= 10) sum += 10;
			else sum += tmp;
		}
		while(sum > 21 && onenum > 0)
		{
			sum -= 10;
			onenum--;
		}
		cout << (sum > 21 ? 0 : sum) << endl;
	}
	return 0;
}