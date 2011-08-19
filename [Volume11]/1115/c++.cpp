#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

// --- lib begin --- //

#include <sstream>
template<class T>
string expand(const string& sep, const T& val){
	ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
string expand(const string& sep, const vector<T>& vt){
//	assert(sep.length() > 0);
	
	string str = "";
	bool first = true;
	for(int i = 0; i < vt.size(); i++){
		if(!first){
			str += sep[0];
		}
		str += expand(sep.substr(1), vt[i]);
		first = false;
	}
	return str;
}

template<class T>
string operator+(const string& sep, const vector<T>& vt){
	return expand(sep, vt);
}

// --- lib end --- //

int plen, cnum, width, cspace;
vector<string> buf;

void bufinit()
{
	buf = vector<string>(plen, string(width*cnum + cspace*(cnum-1), '.'));
}
void bufout()
{
	cout << "\n"+buf << endl << "#" << endl;
}

void lf(int& page, int& line, int& ch)
{
	ch = 0; line++;
	if(line == plen) line = 0, page++;
	if(page == cnum) page = 0, bufout(), bufinit();
}

int main()
{
	while(cin >> plen >> cnum >> width >> cspace, plen)
	{
		cin.ignore();
		string str;
		bufinit();
		
		int page = 0;
		int line = 0;
		int ch = 0;
		while(getline(cin, str), str != "?")
		{
			for(int i = 0; i < str.length(); i++)
			{
				buf[line][page*(width+cspace)+ch] = str[i];
				ch++;
				if(ch == width) lf(page, line, ch);
			}
			if(ch > 0 || str.length() == 0) lf(page, line, ch);
		}
		if(page > 0 || line > 0) bufout();
		cout << "?" << endl;
	}
	return 0;
}
