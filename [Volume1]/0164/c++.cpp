#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		vector<int> seq;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			seq.push_back(tmp);
		}
		
		int num = 31;
		int pos = 0;
		while(num != 1)
		{
			cout << num << endl;
			num -= seq[pos++];
			if(pos == n) pos = 0;
			cout << num << endl;
			num -= (num - 1) % 5;
		}
		cout << 1 << endl << 0 << endl;
	}
	return 0;
}