#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> W(10), K(10);
	for(int i = 0; i < 10; i++)
		cin >> W[i];
	for(int i = 0; i < 10; i++)
		cin >> K[i];
	sort(W.begin(), W.end());
	sort(K.begin(), K.end());
	cout << W[9]+W[8]+W[7] << " " << K[9]+K[8]+K[7] << endl;
	return 0;
}
