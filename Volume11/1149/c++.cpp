#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

ostream& operator<<(ostream& os, pair<int,int> cake)
{
	os << cake.first*cake.second;
	return os;
}

template<class T>
string operator+(const string& sep, const vector<T>& vt){
	return expand(sep, vt);
}

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first*a.second < b.first*b.second;
}

int main()
{
	int n, w, d;
	while(cin >> n >> w >> d, w != 0)
	{
		vector<pair<int,int> > cakes;
		cakes.push_back(pair<int,int>(w,d));
		for(int i = 0; i < n; i++)
		{
			int piece, pos;
			cin >> piece >> pos;
			piece -= 1;
			int curw = cakes[piece].first, curh = cakes[piece].second;
			pos = pos % (curw + curh);
			cakes.erase(cakes.begin()+piece);
			if(pos < curw)
			{
				cakes.push_back(pair<int,int>(min(pos, curw-pos), curh));
				cakes.push_back(pair<int,int>(max(pos, curw-pos), curh));
			}
			else
			{
				cakes.push_back(pair<int,int>(curw, min(pos-curw, curh+curw-pos)));
				cakes.push_back(pair<int,int>(curw, max(pos-curw, curh+curw-pos)));
			}
		}
		sort(cakes.begin(), cakes.end(), cmp);
		cout << " "+cakes << endl;
	}
	return 0;
}
