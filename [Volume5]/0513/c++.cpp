#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// ---------- library code ----------
template<class T>
std::vector<T> gen(T begin, T(&f)(T), int size)
{
//	assert(size >= 0);
	if(size == 0) return std::vector<int>();
	
	std::vector<int> r(size);
	r[0] = begin;
	for(int i = 1; i < size; i++)
	{
		r[i] = (*f)(r[i-1]);
	}
	return r;
}

template<class T>
string operator+(const string& sep, const T& val)
{
	ostringstream oss;
	oss << val;
	return oss.str();
}

template<class T>
string operator+(const string& sep, const vector<T>& vt)
{
	assert(sep.length() > 0);
	
	string str = "";
	bool first = true;
	for(int i = 0; i < vt.size(); i++)
	{
		if(!first) str += sep[0];
		str += sep.substr(1)+vt[i];
		first = false;
	}
	return str;
}

// ---------- library code ----------

int ascending(int x){ return x+1; }

void riffle(std::vector<int>& vi)
{
	std::vector<int> r;
	for(int i = 0; i < vi.size()/2; i++)
	{
		r.push_back(vi[i]);
		r.push_back(vi[i+vi.size()/2]);
	}
	vi = r;
}
void shuffle(std::vector<int>& vi, int n)
{
	reverse(vi.begin(), vi.begin()+n);
	reverse(vi.begin()+n, vi.end());
	reverse(vi.begin(), vi.end());
}

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<int> vi = gen<int>(1, ascending, 2*n);
	while(m--)
	{
		int tmp;
		std::cin >> tmp;
		if(tmp == 0) riffle(vi);
		else shuffle(vi, tmp);
	}
	cout << "\n"+vi << endl;
	return 0;
}