#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y){
	return x % y == 0 ? y : gcd(y, x % y);
}

struct Num
{
	int n, d;
	Num(int n, int d){
		this->n = n;
		this->d = d;
		if(this->d < 0){
			this->n *= -1;
			this->d *= -1;
		}
	}
	
	Num operator-(Num b){
		int _n = this->n * b.d - b.n * this->d;
		int _d = this->d * b.d;
		int _gcd = gcd(_n, _d);
		return Num(_n / _gcd, _d / _gcd);
	}
	
	bool isZero(){
		return n == 0;
	}
	
	bool isNegative(){
		return n < 0;
	}
	
	int limit(int num){
		return num * d / n;
	}
	
	friend ostream& operator<<(ostream& os, Num n){
		os << n.n << "/" << n.d;
		return os;
	}
};

int solve(Num num, int prev, int cur_a, int a, int n){
	if(num.isNegative() || n < 0)
		return 0;
	if(num.isZero())
		return 1;
	
	int r = 0;
	for(int i = prev; i <= num.limit(n); i++)
	{
		if(cur_a * i > a)
			break;
		r += solve(num - Num(1,i), i, cur_a * i, a, n-1);
	}
	
	return r;
}

int main()
{
	int p, q, a, n;
	while(cin >> p >> q >> a >> n, p != 0)
	{
		Num num = Num(p, q);
		cout << solve(num, 1, 1, a, n) << endl;
	}
	return 0;
}
