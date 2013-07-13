#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>
using namespace std;

string correct(int i)
{
	if(i%15 == 0) return "FizzBuzz";
	if(i%3 == 0) return "Fizz";
	if(i%5 == 0) return "Buzz";
	ostringstream oss;
	oss << i;
	return oss.str();
}

int main()
{
	int m, n;
	while(cin >> m >> n, m)
	{
		list<int> ps;
		for(int i = 1; i <= m; i++)
			ps.push_back(i);
		
		list<int>::iterator cur = ps.begin();
		for(int i = 1; i <= n; i++)
		{
			string tmp; cin >> tmp;
			if(ps.size() == 1) continue;
			
			if(tmp == correct(i))  ++cur;
			else cur = ps.erase(cur);
			
			if(cur == ps.end())
				cur = ps.begin();
		}
		for(cur = ps.begin(); cur != ps.end(); ++cur)
			cout << (cur != ps.begin() ? " " : "") << *cur;
		cout << endl;
	}
	return 0;
}
