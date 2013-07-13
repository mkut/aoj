#include <iostream>
using namespace std;

int pow(int x)
{
	int r = 1;
	while(x--)
	{
		r *= 10;
	}
	return r;
}

int main()
{
	const string show[10] = {"* = ****","* =* ***","* =** **","* =*** *","* =**** ",
		" *= ****"," *=* ***"," *=** **"," *=*** *"," *=**** "};
	
	int input;
	bool fst = true;
	while(cin >> input)
	{
		if(!fst) cout << endl;
		fst = false;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 4; j >= 0; j--)
			{
				cout << show[input/pow(j)%10][i];
			}
			cout << endl;
		}
	}
	return 0;
}