#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data{
	string name;
	int yend, end;
	data(string Name, int Yend, int End) : name(Name), yend(Yend), end(End) {}
	bool operator<(const data& a) const{
		return end < a.end;
	}
};

int main()
{
	int N, Q;
	while(cin >> N >> Q, N)
	{
		vector<data> ds;
		for(int i = 0; i < N; i++)
		{
			string name; int a, b;
			cin >> name >> a >> b;
			ds.push_back(data(name, a, b));
		}
		sort(ds.begin(), ds.end());
		for(int i = 0; i < Q; i++)
		{
			int y; cin >> y;
			vector<data>::iterator it = lower_bound(ds.begin(), ds.end(), data("", 0, y));
			if(it != ds.end() && it->end - it->yend < y)
				cout << it->name << " " << y - (it->end - it->yend) << endl;
			else
				cout << "Unknown" << endl;
		}
	}
	return 0;
}
