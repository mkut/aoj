#include <iostream>
#include <algorithm>
using namespace std;

unsigned long xor128(){
    static unsigned long x=123456789,y=362436069,z=521288629,w=88675123;
    unsigned long t;
    t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
}

int main(int argc, char *argv[])
{
	int num = atoi(argv[1]);
	unsigned int A = 8911276, B = 918672, C = 891725;
	unsigned int X = 897631;
	for(int i = 0; i < 4000; i++)
	{
		cout << (char)('A' + X % num);
		X = xor128();
	}
	cout << endl;
	for(int i = 0; i < 4000; i++)
	{
		cout << (char)('A' + X % num);
		X = xor128();
	}
	cout << endl;
	
	return 0;
}
