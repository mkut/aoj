#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;
#include <sstream>
template<class T>
string expand(const string& sep, const T& val){
	ostringstream oss;
	oss << setw(2) << val;
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

typedef vector<vector<int> > Puzzle;

bool operator==(const Puzzle& a, const Puzzle& b)
{
	const int posi[] = {0,1,1,1,2,2,2,2,2,3,3,3,4};
	const int posj[] = {2,1,2,3,0,1,2,3,4,1,2,3,2};
	for(int i = 0; i < 13; i++)
		if(a[posi[i]][posj[i]] != b[posi[i]][posj[i]])
			return false;
	return true;
}

int main()
{
	int n[13];
	while(cin >> n[0], n[0] != -1)
	{
		Puzzle pzl(5);
		for(int i = 0; i < 5; i++)
		{
			pzl[i] = vector<int>(5);
			for(int j = 0; j < 5; j++)
				pzl[i][j] = -1;
		}
		
		const int posi[] = {0,1,1,1,2,2,2,2,2,3,3,3,4};
		const int posj[] = {2,1,2,3,0,1,2,3,4,1,2,3,2};
		Puzzle finish = pzl;
		finish[0][2] = 0;
		finish[1][1] = 1;
		finish[1][2] = 2;
		finish[1][3] = 3;
		finish[2][0] = 4;
		finish[2][1] = 5;
		finish[2][2] = 6;
		finish[2][3] = 7;
		finish[2][4] = 8;
		finish[3][1] = 9;
		finish[3][2] = 10;
		finish[3][3] = 11;
		finish[4][2] = 0;
		
		for(int i = 1; i < 13; i++)
			cin >> n[i];
		for(int i = 0; i < 13; i++)
			pzl[posi[i]][posj[i]] = n[i];
		
		vector<Puzzle> prev;
		set<Puzzle> done;
		prev.push_back(pzl);
		done.insert(done.begin(), pzl);
		bool finished = false;
		for(int ans = 0; ans <= 20; ans++)
		{
			cout << ans << endl;
			cout << done.size() << endl;
			//cout << "\n\n "+prev << endl;
			
			vector<Puzzle> next;
			for(vector<Puzzle>::iterator it = prev.begin(); it != prev.end(); ++it)
			{
				if(*it == finish)
				{
					cout << ans << endl;
					finished = true;
					break;
				}
				for(int i = 0; i < 5; i++)
					for(int j = 0; j < 5; j++)
						if((*it)[i][j] == 0)
						{
							Puzzle npzl = *it;
							const int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
							for(int k = 0; k < 4; k++)
								if(i+dx[k] >= 0 && i+dx[k] < 5 && j+dy[k] >= 0 && j+dy[k] < 5 && npzl[i+dx[k]][j+dy[k]] != -1)
								{
									swap(npzl[i][j], npzl[i+dx[k]][j+dy[k]]);
									if(done.insert(npzl).second)
										next.push_back(npzl);
									swap(npzl[i][j], npzl[i+dx[k]][j+dy[k]]);
								}
						}
			}
			if(finished)
				break;
			prev = next;
		}
		if(!finished)
			cout << "NA" << endl;
	}
	return 0;
}
