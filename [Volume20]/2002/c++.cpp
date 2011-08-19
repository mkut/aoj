#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int fact[] = {1,1,2,6,24,120,720,5040,40320};

int main()
{
	int T; cin >> T;
	while(T--)
	{
		int H, W; cin >> H >> W;
		vector<string> img(H);
		for(int i = 0; i < H; i++)
			cin >> img[i];
		vector<char> cs;
		map<char,int> L, R, T, B;
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++)
			{
				char c = img[i][j];
				if(c == '.') continue;
				if(!count(cs.begin(), cs.end(), c))
					cs.push_back(c);
				if(!L.count(c)) L[c] = j; else L[c] = min(L[c], j);
				if(!R.count(c)) R[c] = j; else R[c] = max(R[c], j);
				if(!T.count(c)) T[c] = i; else T[c] = min(T[c], i);
				if(!B.count(c)) B[c] = i; else B[c] = max(B[c], i);
			}
		bool ok = false;
		for(int p = 0; p < fact[cs.size()]; p++)
		{
			map<char,int> perm;
			for(int i = 0; i < cs.size(); i++)
				perm[cs[i]] = i;
			bool ok_cur = true;
			for(int i = 0; i < cs.size(); i++)
			{
				char c = cs[i];
				for(int j = T[c]; j <= B[c]; j++)
					for(int k = L[c]; k <= R[c]; k++)
						if(img[j][k] == '.' || perm[img[j][k]] > perm[c]) { ok_cur = false; break; }
				if(!ok_cur)
					break;
			}
			if(ok_cur) { ok = true; break; }
			next_permutation(cs.begin(), cs.end());
		}
		cout << (ok ? "SAFE" : "SUSPICIOUS") << endl;
	}
	return 0;
}
