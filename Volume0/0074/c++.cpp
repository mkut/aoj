#include <iostream>
using namespace std;

int main()
{
	int h, m, s;
	while(cin >> h >> m >> s, h != -1 || m != -1 || s != -1)
	{
		int ans = 2*60*60 - h*60*60 - m*60 - s;
		int ansx3 = ans * 3;
		printf("%02d:%02d:%02d\n", ans/60/60, ans/60%60, ans%60);
		printf("%02d:%02d:%02d\n", ansx3/60/60, ansx3/60%60, ansx3%60);
	}
	return 0;
}