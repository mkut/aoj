#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	map<string,int> cnv;
	cnv["yotta"] = 24;
	cnv["zetta"] = 21;
	cnv["exa"] = 18;
	cnv["peta"] = 15;
	cnv["tera"] = 12;
	cnv["giga"] = 9;
	cnv["mega"] = 6;
	cnv["kilo"] = 3;
	cnv["hecto"] = 2;
	cnv["deca"] = 1;
	cnv["deci"] = -1;
	cnv["centi"] = -2;
	cnv["milli"] = -3;
	cnv["micro"] = -6;
	cnv["nano"] = -9;
	cnv["pico"] = -12;
	cnv["femto"] = -15;
	cnv["ato"] = -18;
	cnv["zepto"] = -21;
	cnv["yocto"] = -24;

	int t;
	cin >> t;
	while(t--)
	{
		string num, sup, unit;
		int isup = 0;
		cin >> num >> sup;
		if(cnv.count(sup) == 0)
			unit = sup;
		else
		{
			isup = cnv[sup];
			cin >> unit;
		}
		if(num[0] == '0')
		{
			for(int i = 1; i < num.size(); i++)
			{
				if(num[i] >= '1' && num[i] <= '9')
				{
					num = num.substr(i);
					break;
				}
				isup--;
			}
		}
		else
		{
			for(int i = 1; i < num.size(); i++)
			{
				if(num[i] == '.')
				{
					num = num.substr(0,i) + num.substr(i+1);
					break;
				}
				isup++;
			}
		}
		cout << num[0] << (num.size() == 1 ? "" : ".") << num.substr(1) << " * 10^" << isup << " " << unit << endl;
	}
	return 0;
}
