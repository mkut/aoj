/* aoj header */
#include <map>

int main()
{
	map<char, char> rep;
	rep['i'] = 'i';
	rep['w'] = 'w';
	rep['('] = ')';
	rep[')'] = '(';

	string input; cin >> input;
	int ans = 0;
	int n = input.length();
	for(int i = 0; i < (n+1)/2; i++)
		ans += input[i] != rep[input[n-1-i]] ? 1 : 0;
	cout << ans << endl;
	return 0;
}
