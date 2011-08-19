#include <iostream>
#include <vector>
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
	while(getline(cin, input), input != "END OF INPUT")
	{
		vector<string> nums = split(input, ' ');
		for(int i = 0; i < nums.size(); i++)
		{
			cout << nums[i].length();
		}
		cout << endl;
	}
	return 0;
}