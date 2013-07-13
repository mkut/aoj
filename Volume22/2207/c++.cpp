#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <iomanip>
using namespace std;

#define INF 1000000

int index(vector<string>& lst, string str)
{
	for(int i = 0; i < lst.size(); i++)
		if(lst[i] == str)
			return i;
	
	lst.push_back(str);
	return lst.size()-1;
}

int main()
{
	int n;
	while(cin >> n, n)
	{
		bool ok = true;
		
		vector<string> lst;
		
		vector<vector<int> > mat(2*n);
		for(int i = 0; i < 2*n; i++)
		{
			mat[i] = vector<int>(2*n);
			for(int j = 0; j < 2*n; j++)
				mat[i][j] = INF;
		}
		while(n--)
		{
			int one, x, iA, iB;
			string A, B, eq, strx;
			cin >> one >> A >> eq >> strx >> B;
			
			iA = index(lst, A);
			iB = index(lst, B);
			x = atoi(strx.substr(3).c_str());
			
			mat[iA][iB] = x;
			mat[iB][iA] = -x;
			
			if(iA == iB && x != 0)
				ok = false;
		}
		
		for(int k = 0; k < lst.size(); k++)
			for(int i = 0; i < lst.size(); i++)
				for(int j = 0; j < lst.size(); j++)
					if(mat[i][j] == INF && mat[i][k] != INF && mat[k][j] != INF)
						mat[i][j] = mat[i][k] + mat[k][j];
					else if(mat[i][j] != INF && mat[i][k] != INF && mat[k][j] != INF && mat[i][j] != mat[i][k] + mat[k][j])
						ok = false;
		
		/*
		for(int i = 0; i < lst.size(); i++)
		{
			cout << setw(10) << lst[i] << " ";
			for(int j = 0; j < lst.size(); j++)
				cout << setw(3) << mat[i][j] << " ";
			cout << endl;
		}
		cout << endl;
		*/
		
		cout << (ok ? "Yes" : "No") << endl;
	}
	
	return 0;
}
