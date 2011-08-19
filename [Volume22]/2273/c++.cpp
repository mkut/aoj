/* aoj header */
#include <set>

string itos(int x)
{
	string ret;
	for(;x; x/=26)
		ret += 'a' + x%26;
	return ret;
}

int main()
{
	set<string> used;
	char prev = 'a';
	for(int i = 1; ; i++)
	{
		cout << "?" << prev << itos(i) << "a" << endl;
		string str;
		cin >> str;
		if(str[0] != 'a' || used.count(str))
		{
			cout << "!OUT" << endl;
			break;
		}
		used.insert(str);
		prev = str[str.length()-1];
	}
	return 0;
}
