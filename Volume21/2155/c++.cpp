#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct packet
{
	int t, s, d;
	packet(int t, int s, int d) : t(t), s(s), d(d) {}
	bool operator<(const packet& a) const { return t < a.t; }
};

int main()
{
	int N, M;
	while(cin >> N >> M, N)
	{
		vector<packet> packets;
		for(int i = 0; i < M; i++)
		{
			int t, s, d; cin >> t >> s >> d; s--; d--;
			packets.push_back(packet(t, s, d));
		}
		sort(packets.begin(), packets.end());
		vector<char> infected(N); infected[0] = 1;
		for(int i = 0; i < M; i++)
			if(infected[packets[i].s]) infected[packets[i].d] = 1;
		int ans = 0;
		for(int i = 0; i < N; i++)
			if(infected[i])
				ans++;
		cout << ans << endl;
	}
	return 0;
}
