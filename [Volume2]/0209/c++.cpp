#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(vector<vector<int> >& view, vector<vector<int> >& piece, int Y, int X)
{
	int res = 1000000;
	int topleft;
	bool ok;
	
	ok = true;
	topleft = 1000000;
	for(int i = 0; i < piece.size(); i++)
		for(int j = 0; j < piece.size(); j++)
		{
			if(piece[i][j] != -1 && piece[i][j] != view[Y+i][X+j])
				ok = false;
			if(piece[i][j] != -1)
				topleft = min(topleft, (Y+i)*1000+(X+j));
		}
	if(ok) res = min(res, topleft);
	
	ok = true;
	topleft = 1000000;
	for(int i = 0; i < piece.size(); i++)
		for(int j = 0; j < piece.size(); j++)
		{
			if(piece[piece.size()-1-j][i] != -1 && piece[piece.size()-1-j][i] != view[Y+i][X+j])
				ok = false;
			if(piece[piece.size()-1-j][i] != -1)
				topleft = min(topleft, (Y+i)*1000+(X+j));
		}
	if(ok) res = min(res, topleft);
	
	ok = true;
	topleft = 1000000;
	for(int i = 0; i < piece.size(); i++)
		for(int j = 0; j < piece.size(); j++)
		{
			if(piece[piece.size()-1-i][piece.size()-1-j] != -1 && piece[piece.size()-1-i][piece.size()-1-j] != view[Y+i][X+j])
				ok = false;
			if(piece[piece.size()-1-i][piece.size()-1-j] != -1)
				topleft = min(topleft, (Y+i)*1000+(X+j));
		}
	if(ok) res = min(res, topleft);
	
	ok = true;
	topleft = 1000000;
	for(int i = 0; i < piece.size(); i++)
		for(int j = 0; j < piece.size(); j++)
		{
			if(piece[j][piece.size()-1-i] != -1 && piece[j][piece.size()-1-i] != view[Y+i][X+j])
				ok = false;
			if(piece[j][piece.size()-1-i] != -1)
				topleft = min(topleft, (Y+i)*1000+(X+j));
		}
	if(ok) res = min(res, topleft);
	
	return res;
}

int main()
{
	int n, m;
	while(cin >> n >> m, n)
	{
		vector<vector<int> > view(n), piece(m);
		for(int i = 0; i < n; i++)
		{
			view[i] = vector<int>(n);
			for(int j = 0; j < n; j++)
				cin >> view[i][j];
		}
		for(int i = 0; i < m; i++)
		{
			piece[i] = vector<int>(m);
			for(int j = 0; j < m; j++)
				cin >> piece[i][j];
		}
		
		int Y = 1000, X = 1000;
		for(int i = 0; i <= n-m; i++)
		{
			for(int j = 0; j <= n-m; j++)
			{
				int tmp = check(view, piece, i, j);
				if(Y*1000 + X > tmp)
				{
					Y = tmp / 1000;
					X = tmp % 1000;
				}
			}
		}
		if(Y == 1000) cout << "NA" << endl;
		else cout << X+1 << " " << Y+1 << endl;
	}
	return 0;
}
