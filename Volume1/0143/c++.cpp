#include <iostream>
using namespace std;

bool left_vector(double startx, double starty, double x, double y)
{
	return startx*y - starty*x > 0;
}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x[5], y[5];
		for(int i = 0; i < 5; i++) cin >> x[i] >> y[i];
		
		bool inner_k, inner_s;
		inner_k = left_vector(x[1]-x[0], y[1]-y[0], x[3]-x[0], y[3]-y[0]) == left_vector(x[2]-x[1], y[2]-y[1], x[3]-x[1], y[3]-y[1])
			&& left_vector(x[1]-x[0], y[1]-y[0], x[3]-x[0], y[3]-y[0]) == left_vector(x[0]-x[2], y[0]-y[2], x[3]-x[2], y[3]-y[2]);
		inner_s = left_vector(x[1]-x[0], y[1]-y[0], x[4]-x[0], y[4]-y[0]) == left_vector(x[2]-x[1], y[2]-y[1], x[4]-x[1], y[4]-y[1])
			&& left_vector(x[1]-x[0], y[1]-y[0], x[4]-x[0], y[4]-y[0]) == left_vector(x[0]-x[2], y[0]-y[2], x[4]-x[2], y[4]-y[2]);
		if(inner_k == inner_s) cout << "NG" << endl;
		else cout << "OK" << endl;
	}
	return 0;
}