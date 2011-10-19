#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

template<class T>
istream& operator>>(istream& is, vector<T>& v) {
	for(int i = 0; i < v.size(); i++)
		cin >> v[i];
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v) {
	for(int i = 0; i < v; i++)
		cout << v[i];
	return os;
}

template<class T>
class vector_reader {
public:
	typedef enum { FORMAT_NONE, FORMAT_VEC, FORMAT_LEN_VEC } format;
	typedef enum { ARG_NONE, ARG_LENGTH } arg;
private:
	vector<T>& v;
	format f;
public:
	vector_reader(vector<T>& v, format f) : v(v), f(f) { }
	vector_reader(vector<T>& v, format f, arg a, int arg1) : v(v), f(f) {
		vector_reader(v, f);
		switch(a) {
		case ARG_LENGTH:
			v = vector<T>(arg1);
			break;
		}
	}
	friend istream& operator>>(istream& is, vector_reader vr) {
		int len;
		switch(vr.f) {
		case FORMAT_VEC:
			return is >> vr.v;
		case FORMAT_LEN_VEC:
			is >> len;
			vr.v = vector<T>(len);
			return is >> vr.v;
		}
	}
};
template<class T>
class vector_writer {
private:
	const vector<T>& v;
	char sep;
public:
	vector_writer(const vector<T>& v, char sep)
		: v(v), sep(sep) {}
	friend ostream& operator<<(ostream& os, vector_writer vw) {
		for(int i = 0; i < vw.v.size(); i++) {
			if(i != 0)
				os << vw.sep;
			os << vw.v[i];
		}
		return os;
	}
};


struct key {
	int a;
	 int b;
	key() {}
	key(int a, int b) : a(a),b(b) {}
	friend istream& operator>>(istream& is, key& __key) {
		is >> __key.a  >> __key.b ;
	}
	friend ostream& operator<<(ostream& os, key& __key) {
		os << __key.a  << __key.b ;
	}
};


class solver
{
private:
	int N;
	string message, ans;
	vector<key> vk;
public:
	friend istream& operator>>(istream& is, solver& cl){
		is >> cl.N;
		is >> cl.message;
		is >> vector_reader<key >(cl.vk, vector_reader<key>::FORMAT_VEC, vector_reader<key>::ARG_LENGTH, cl.N);
		return is;
	}
	friend ostream& operator<<(ostream& os, solver& cl){
		os << cl.ans << endl;
		return os;
	}
	void solve()
	{
		ans = message;
		for(int i = N-1; i >= 0; i--)
		{
			int a = vk[i].a - 1;
			int b = vk[i].b - 1;
			char tmp = ans[a];
			ans[a] = ans[b];
			ans[b] = tmp;
			ans[a] = add(ans[a], abs(a-b));
			ans[b] = add(ans[b], abs(a-b));
		}
	}
	char add(char c, int x) { return 'a' + (c - 'a' + x) % 26; }
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
	}
	return 0;
}
