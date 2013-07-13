#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

string chars[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
	"u", "v", "w", "x", "y", "z", "ld", "mb", "mp", "nc", "nd", "ng", "nt", "nw", "ps", "qu", "cw", "ts"};

int match(string& str, int pos)
{
	if(pos < str.length()-1)
		for(int i = 26; i < 38; i++)
			if(str[pos] == chars[i][0] && str[pos+1] == chars[i][1])
				return i;
	return str[pos] - 'a';
}

int main()
{
	int n; cin >> n;
	string str;
	vector<vector<int> > count(38, vector<int>(38));
	while(cin >> str)
	{
		int prev = -1;
		for(int i = 0; i < str.length(); )
		{
			int c = match(str, i);
			if(prev != -1)
				count[prev][c]++;
			prev = c;
			i += c < 26 ? 1 : 2;
		}
	}
	for(int i = 0; i < 38; i++)
	{
		int max_count = 0, max_j = 0;
		for(int j = 0; j < 38; j++)
			if(max_count < count[i][j])
				max_count = count[i][j], max_j = j;
		cout << chars[i] << " " << chars[max_j] << " " << max_count << endl;
	}
	return 0;
}
