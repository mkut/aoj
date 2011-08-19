#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	string id;
	while(getline(cin, id, ','))
	{
		string sweight, sheight;
		getline(cin, sweight, ',');
		getline(cin, sheight);
		double weight = atof(sweight.c_str());
		double height = atof(sheight.c_str());
		if(weight/height/height >= 25) cout << id << endl;
	}
	return 0;
}