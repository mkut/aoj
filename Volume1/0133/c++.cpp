#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> pic;
	string tmp;
	while(cin >> tmp) pic.push_back(tmp);
	
	cout << 90 << endl;
	for(int j = 0; j < pic[0].length(); j++)
	{
		for(int i = pic.size()-1; i >= 0; i--)
		{
			cout << pic[i][j];
		}
		cout << endl;
	}
	cout << 180 << endl;
	for(int i = pic.size()-1; i >= 0; i--)
	{
		for(int j = pic[0].length()-1; j >= 0; j--)
		{
			cout << pic[i][j];
		}
		cout << endl;
	}
	cout << 270 << endl;
	for(int j = pic[0].length()-1; j >= 0; j--)
	{
		for(int i = 0; i < pic.size(); i++)
		{
			cout << pic[i][j];
		}
		cout << endl;
	}
	
	return 0;
}