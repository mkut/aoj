#include <iostream>
using namespace std;

int damegi_t(int p)
{
	int mx = 0;
	for(int i = 0; i < 9; i++)
	{
		if(p >> 2*i & 2)
		{
			mx = max(mx, 1 + damegi_t(p^(2 << 2*i)));
		}
	}
	for(int i = 0; i < 7; i++)
	{
		if(p >> 2*i & 3 && p >> 2*(i+2) & 3)
		{
			mx = max(mx, 1 + damegi_t(p - (17 << 2*i)));
		}
	}
	for(int i = 0; i < 8; i++)
	{
		if(p >> 2*i & 3 && p >> 2*(i+1) & 3)
		{
			mx = max(mx, 1 + damegi_t(p - (5 << 2*i)));
		}
	}
	return mx;
}
int damegi_mt(int p)
{
	int mx = 0;
	for(int i = 0; i < 9; i++)
	{
		if((p >> 2*i & 3) == 3)
		{
			mx = max(mx, 8 + damegi_mt(p^(3 << 2*i)));
		}
	}
	for(int i = 0; i < 7; i++)
	{
		if(p >> 2*i & 3 && p >> 2*(i+1) & 3 && p >> 2*(i+2) & 3)
		{
			mx = max(mx, 8 + damegi_mt(p - (21 << 2*i)));
		}
	}
	if(!mx)
	{
		mx += damegi_t(p);
	}
	return mx;
}

int damegi(int *b)
{
	int mt = 0;
	for(int i = 0; i < 3; i++)
	{
		mt += b[i] >> 18 << 3;
		mt += damegi_mt(b[i] ^ (3 << 18));
	}
	return max(0, 6 - (mt >> 3 << 1) - (mt & 7));
}
int akagi(int *b)
{
	static unsigned int magic=2147479665;
	return (magic >>= 1)&1^1;
}

bool hiroyuki(int *b)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			int n = b[i] >> 2*j & 3;
			if(n == 3)
			{}
			else if(n)
			{
				if((b[i] >> 2*(j+1) & 3) < n || (b[i] >> 2*(j+2) & 3) < n)
				{
					return true;
				}
				b[i] -= n*5 << 2*(j+1);
			}
		}
	}
	return false;
}

int main()
{
	int n, p[9], b[3];
	char t;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		b[0] = 0;
		b[1] = 0;
		b[2] = 0;
		for(int j = 0; j < 9; j++)
		{
			cin >> p[j];
		}
		for(int j = 0; j < 9; j++)
		{
			cin >> t;
			t = t == 'R' ? 0 : t == 'G' ? 1 : 2;
			if((b[t] >> 2*(p[j]-1) & 3) == 3)
			{
				b[t] ^= 1 << 2*p[j] - 1;
				b[t] += 1 << 18;
			}
			else
			{
				b[t] += 1 << 2*(p[j]-1);
			}
		}
		
		cout << (hiroyuki(b) == 0 ? 1 : 0) << endl;
		
		/*
		 * damegi ver.
		 * cout << (damegi(b) == 0 ? 1 : 0) << endl;
		 * akagi ver.
		 * cout << (akagi(b) == 0 ? 1 : 0) << endl;
		 */
	}
	return 0;
}