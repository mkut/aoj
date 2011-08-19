#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m, n != 0)
	{
		vector<int> taro, hanako;
		int tarosum = 0, hanakosum = 0;
		for(int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			taro.push_back(tmp);
			tarosum += tmp;
		}
		for(int i = 0; i < m; i++)
		{
			int tmp; cin >> tmp;
			hanako.push_back(tmp);
			hanakosum += tmp;
		}
		if((tarosum - hanakosum) & 1)
		{
			cout << -1 << endl;
			continue;
		}
		bool finished = false;
		for(int i = 0; i < taro.size(); i++)
		{
			if(count(hanako.begin(), hanako.end(), taro[i] + (hanakosum - tarosum)/2) > 0)
			{
				cout << taro[i] << " " << taro[i] + (hanakosum - tarosum)/2 << endl;
				finished = true;
				break;
			}
		}
		if(!finished)
			cout << -1 << endl;
	}
	return 0;
}
