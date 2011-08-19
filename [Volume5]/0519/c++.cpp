#include <iostream>
#include <vector>
#include <bitset>
#include <stdlib.h>
using namespace std;

int gcd(int x, int y)
{
	return x % y == 0 ? y : gcd(y, x % y);
}
int lcm(int x, int y)
{
	return x / gcd(x,y) * y;
}

struct Stick
{
	Stick* r;
	Stick* b;
	int p;
	int q;
	
	Stick(int p, int q, int r, int b, vector<int>& vp, vector<int>& vq, vector<int>& vr, vector<int>& vb)
	{
		if(r == 0) this->r = NULL;
		else
		{
			this->r = new Stick(vp[r-1], vq[r-1], vr[r-1], vb[r-1], vp, vq, vr, vb);
		}
		if(b == 0) this->b = NULL;
		else
		{
			this->b = new Stick(vp[b-1], vq[b-1], vr[b-1], vb[b-1], vp, vq, vr, vb);
		}
		this->p = p / gcd(p,q);
		this->q = q / gcd(p,q);
	}
	~Stick()
	{
		if(r != NULL) delete r;
		if(b != NULL) delete b;
	}
	
	int weight()
	{
		int wr = r == NULL ? 1 : r->weight();
		int wb = b == NULL ? 1 : b->weight();
		int _lcm = lcm(wr * p, wb * q);
		return _lcm / p + _lcm / q;
	}
};

int main()
{
	int n;
	while(cin >> n, n != 0)
	{
		bitset<1000> used;
		vector<int> vp(n), vq(n), vr(n), vb(n);
		for(int i = 0; i < n; i++)
		{
			cin >> vp[i] >> vq[i] >> vr[i] >> vb[i];
			if(vr[i] != 0) used[vr[i]-1] = true;
			if(vb[i] != 0) used[vb[i]-1] = true;
		}
		Stick* root;
		for(int i = 0; i < 1000; i++)
		{
			if(!used[i])
			{
				root = new Stick(vp[i], vq[i], vr[i], vb[i], vp, vq, vr, vb);
				break;
			}
		}
		cout << root->weight() << endl;
		delete root;
	}
	return 0;
}