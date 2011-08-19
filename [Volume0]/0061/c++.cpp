#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	string snumber, sscore;
	int scoretorank[32] = {};
	map<int, int> numbertoscore;
	while(getline(cin, snumber, ','), getline(cin, sscore), snumber != "0" || sscore != "0")
	{
		int score = atoi(sscore.c_str());
		if(scoretorank[score] == scoretorank[score+1]) for(int i = score; i >= 0; i--) scoretorank[i]++;
		numbertoscore[atoi(snumber.c_str())] = score;
	}
	int n;
	while(cin >> n)
	{
		cout << scoretorank[numbertoscore[n]] << endl;
	}
	
	return 0;
}