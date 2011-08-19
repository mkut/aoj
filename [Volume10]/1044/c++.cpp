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

int curtype(string str)
{
	bool capital = str[0] >= 'A' && str[0] <= 'Z';
	bool under = false;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '_') under = true;
	}
	
	// 1 : U GetName
	// 2 : L getName
	// 3 : D get_name
	return under ? 3 : (capital ? 1 : 2);
}

vector<string> parse(string str, int type)
{
	vector<string> r;
	if(type == 1)
	{
		for(int i = 1; i < str.size(); i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				r.push_back((char)(str[0]-'A'+'a') + str.substr(1, i-1));
				str = str.substr(i);
				i = 0;
			}
		}
		r.push_back((char)(str[0]-'A'+'a') + str.substr(1));
	}
	else if(type == 2)
	{
		bool pl = false;
		for(int i = 1; i < str.size(); i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				r.push_back(str.substr(0,i));
				str = str.substr(i);
				pl = true;
				break;
			}
		}
		for(int i = 1; i < str.size(); i++)
		{
			if(str[i] >= 'A' && str[i] <= 'Z')
			{
				r.push_back((char)(str[0]-'A'+'a') + str.substr(1, i-1));
				str = str.substr(i);
				i = 0;
			}
		}
		if(pl) r.push_back((char)(str[0]-'A'+'a') + str.substr(1));
		else r.push_back(str.substr(0));
	}
	else
	{
		r = split(str, '_');
	}
	return r;
}

string cnv(vector<string> vs, int type)
{
	string r = "";
	if(type == 1)
	{
		for(int i = 0; i < vs.size(); i++)
		{
			vs[i][0] += 'A'-'a';
			r += vs[i];
		}
	}
	else if(type == 2)
	{
		for(int i = 0; i < vs.size(); i++)
		{
			if(i != 0) vs[i][0] += 'A'-'a';
			r += vs[i];
		}
	}
	else
	{
		for(int i = 0; i < vs.size(); i++)
		{
			if(i != 0) vs[i] = '_' + vs[i];
			r += vs[i];
		}
	}
	return r;
}

int main()
{
	string name;
	char type;
	while(cin >> name >> type)
	{
		if(type == 'X') break;
		vector<string> vs;
		vs = parse(name, curtype(name));
		cout << cnv(parse(name, curtype(name)), (type=='U' ? 1 : (type=='L' ? 2 : 3))) << endl;
	}
	
	return 0;
}