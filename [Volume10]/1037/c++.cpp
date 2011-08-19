#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

struct BinaryTree
{
	BinaryTree *left, *right;
	vector<long long> ans;
	
	BinaryTree(string str, vector<int>& leaves) : ans(16), left(NULL), right(NULL)
	{
		if(str[0] == '(')
		{
			int nest = 0;
			for(int i = 1; i < str.length(); i++)
			{
				if(str[i] == '(') nest++;
				if(str[i] == ')') nest--;
				if(nest == 0 && str[i] == ' ')
				{
					left = new BinaryTree(str.substr(1, i-1), leaves);
					right = new BinaryTree(str.substr(i+1, str.length()-i-2), leaves);
					break;
				}
			}
			for(int i = 0; i < 16; i++)
				for(int j = 0; j < 16; j++)
				{
					ans[i&j] += left->ans[i] * right->ans[j];
					ans[i|j] += left->ans[i] * right->ans[j];
					ans[i^j] += left->ans[i] * right->ans[j];
				}
		}
		else ans[leaves[str[0]-'1']] = 1;
	}
	~BinaryTree() { delete left; delete right; }
};

class solver
{
	BinaryTree* root;
public:
	solver(string str, vector<int>& leaves) { root = new BinaryTree(str, leaves); }
	~solver() { delete root; }
	long long solve() { return root->ans[15]; }
};

int main()
{
	string tree;
	while(getline(cin, tree), tree != "END")
	{
		int n; cin >> n;
		vector<int> leaves(n);
		for(int i = 0; i < n; i++)
		{
			int t[4]; cin >> t[0] >> t[1] >> t[2] >> t[3];
			leaves[i] = t[0]*8+t[1]*4+t[2]*2+t[3];
		}
		solver prob(tree, leaves);
		cout << prob.solve() << endl;
		
		getline(cin, tree); // LF
	}
	return 0;
}
