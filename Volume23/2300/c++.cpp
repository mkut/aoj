#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct color {
	double L, a, b;
	color(double L, double a, double b) : L(L), a(a), b(b) {}
};

double sqr(double a) {
	return a * a;
}

double diff(color& a, color& b) {
	return sqr(a.L - b.L) + sqr(a.a - b.a) + sqr(a.b - b.b);
}

bool nth(int x, int n) {
	return (x >> n) & 1;
}

int main() {
	int N, M; cin >> N >> M;
	vector<color> cs;
	for (int i = 0; i < N; i++) {
		double L, a, b;
		cin >> L >> a >> b;
		cs.push_back(color(L, a, b));
	}

	vector<vector<double> > dist(N, vector<double>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dist[i][j] = diff(cs[i], cs[j]);

	double ans = 0;
	for (int i = 0; i < 1<<N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++)
			cnt += nth(i, j);
		if (cnt == M) {
			double tmp = 0;
			for (int j = 0; j < N; j++)
				if (nth(i, j))
					for (int k = j + 1; k < N; k++)
						if (nth(i, k))
							tmp += dist[j][k];
			ans = max(ans, tmp);
		}
	}

	printf("%.9f\n", ans);
	return 0;
}
