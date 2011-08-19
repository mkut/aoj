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

int calc(string str)
{
	int num = 0, num2 = 1, num2_d = 1;
	bool mlt = true;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			num = num*10 + str[i] - '0';
		}
		else if(str[i] == '+')
		{
			if(mlt) num2 *= num;
			else num2_d *= num;
			int _calc = calc(str.substr(i+1));
			return num2_d != 0 && num2 % num2_d == 0 && _calc != -1000000 ? num2 / num2_d + _calc : -1000000;
		}
		else if(str[i] == '-')
		{
			if(mlt) num2 *= num;
			else num2_d *= num;
			int _calc = calc(str.substr(i+1));
			return num2_d != 0 && num2 % num2_d == 0 && _calc != -1000000 ? num2 / num2_d - _calc : -1000000;
		}
		else if(str[i] == '*' || str[i] == '/')
		{
			if(mlt) num2 *= num;
			else num2_d *= num;
			mlt = str[i] == '*';
			num = 0;
		}
	}
	if(mlt) num2 *= num;
	else num2_d *= num;
	
	return num2_d != 0 && num2 % num2_d == 0 ? num2 / num2_d : -1000000;
}

bool valid(string str)
{
	if(str.length() == 1) return true;
	
	bool complete = true;
	int state = 0;
	// 0 : 0-9
	// 1 : ope
	// 2 : all
	int eqnum = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '.')
		{
			complete = false;
			state = 2;
		}
		else if(str[i] >= '1' && str[i] <= '9')
		{
			if(state == 1) return false;
			state = 2;
		}
		else if(str[i] == '0')
		{
			if(state == 1) return false;
			else if(state == 0) state = 1;
		}
		else
		{
			if(state == 0) return false;
			if(str[i] == '=') eqnum++;
			state = 0;
		}
	}
	if(str[str.length()-1] == '+' || str[str.length()-1] == '-' || str[str.length()-1] == '*' || str[str.length()-1] == '/' || str[str.length()-1] == '=') return false;
	if(eqnum >= 2)  return false;
	if(eqnum == 0 && complete) return false;
	if(!complete) return true;
	
	vector<string> eq = split(str, '=');
	return calc(eq[0]) == calc(eq[1]) && calc(eq[0]) != -1000000;
}

bool solve(vector<string> pzl, string alt)
{
	if(alt.length() == 0)
	{
		for(int i = 0; i < pzl.size(); i++)
		{
			cout << pzl[i] << endl;
		}
		return true;
	}
	
	for(int i = 0; i < pzl.size(); i++)
	{
		for(int j = 0; j < pzl[i].length(); j++)
		{
			if(pzl[i][j] == '.')
			{
				for(int k = 0; k < alt.length(); k++)
				{
					string yoko = "";
					yoko += alt[k];
					for(int J = j-1; J >= 0; J--)
					{
						if(pzl[i][J] == '#') break;
						yoko = pzl[i][J] + yoko;
					}
					for(int J = j+1; J < pzl[i].length(); J++)
					{
						if(pzl[i][J] == '#') break;
						yoko = yoko + pzl[i][J];
					}
					//cout << "yoko" << ":" << yoko << ":" << valid(yoko) << endl;
					if(!valid(yoko)) continue;
					
					string tate = "";
					tate += alt[k];
					for(int I = i-1; I >= 0; I--)
					{
						if(pzl[I][j] == '#') break;
						tate = pzl[I][j] + tate;
					}
					for(int I = i+1; I < pzl.size(); I++)
					{
						if(pzl[I][j] == '#') break;
						tate = tate + pzl[I][j];
					}
					//cout << "tate" << ":" << tate << ":" << valid(tate) << endl;
					if(!valid(tate)) continue;
					
					pzl[i][j] = alt[k];
					if(solve(pzl, alt.substr(0, k) + alt.substr(k+1))) return true;
					pzl[i][j] = '.';
				}
				return false;
			}
		}
	}
	return false;
}

int main()
{
	string input;
	//while(cin >> input) cout << valid(input) << endl;
	
	int H, W;
	while(cin >> H >> W, H != 0)
	{
		vector<string> puzzle;
		for(int i = 0; i < H; i++)
		{
			string tmp; cin >> tmp;
			puzzle.push_back(tmp);
		}
		
		int n;
		cin >> n;
		string alt;
		for(int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			alt += str;
		}
		
		cout << (solve(puzzle, alt) ? "Yes" : "No") << endl;
	}
	return 0;
}