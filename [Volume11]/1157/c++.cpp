#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

inline double size_v(double x, double y){
	return sqrt(x * x + y * y);
}
inline bool left_vv(double startx, double starty, double x, double y){
	return startx*y - starty*x >= 0;
}
inline bool right_vv(double startx, double starty, double x, double y){
	return startx*y - starty*x <= 0;
}
inline bool forward_vv(double x1, double y1, double x2, double y2){
	return x1*x2 + y1*y2 >= 0;
}
inline bool cross_ss(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22){
	return (left_vv(x12 - x11, y12 - y11, x21 - x11, y21 - y11) && right_vv(x12 - x11, y12 - y11, x22 - x11, y22 - y11) ||
			right_vv(x12 - x11, y12 - y11, x21 - x11, y21 - y11) && left_vv(x12 - x11, y12 - y11, x22 - x11, y22 - y11)) &&
			(left_vv(x22 - x21, y22 - y21, x11 - x21, y11 - y21) && right_vv(x22 - x21, y22 - y21, x12 - x21, y12 - y21) ||
			right_vv(x22 - x21, y22 - y21, x11 - x21, y11 - y21) && left_vv(x22 - x21, y22 - y21, x12 - x21, y12 - y21)) &&
}
inline double distance_lp(double x1, double y1, double x2, double y2, double x, double y){
	return fabs((y-y1)*(x2-x1) - (x-x1)*(y2-y1)) / size_v(x1-x2, y1-y2);
}
inline double distance_sp(double x1, double y1, double x2, double y2, double x, double y){
	if(forward_vv(x2 - x1, y2 - y1, x - x1, y - y1) && forward_vv(x1 - x2, y1 - y2, x - x2, y - y2))
		return distance_lp(x1, y1, x2, y2, x, y);
	else
		return min(size_v(x - x1, y - y1), size_v(x - x2, y - y2));
}
inline double distance_ss(double x11, double y11, double x12, double y12, double x21, double y21, double x22, double y22){
	if(cross_ss(x11, y11, x12, y12, x21, y21, x22, y22))
		return 0;
	else
		return min(min(distance_sp(x11, y11, x12, y12, x21, y21), distance_sp(x11, y11, x12, y12, x22, y22)),
			min(distance_sp(x21, y21, x22, y22, x11, y11), distance_sp(x21, y21, x22, y22, x12, y12)));
}

inline bool inner_sqr(double x1, double y1, double x2, double y2, double x, double y)
{
	return x1 <= x && x <= x2 && y1 <= y && y <= y2;
}

int main()
{
	int N;
	while(cin >> N, N != 0)
	{
		double sx, sy, gx, gy;
		cin >> sx >> sy >> gx >> gy;
		
		double ans = 1e8;
		for(int i = 0; i < N; i++)
		{
			double x1, y1, x2, y2, h;
			cin >> x1 >> y1 >> x2 >> y2 >> h;
			if(inner_sqr(x1, y1, x2, y2, sx, sy))
				ans = 0;
			if(inner_sqr(x1, y1, x2, y2, gx, gy))
				ans = 0;
			
			double d = min(min(distance_ss(x1, y1, x1, y2, sx, sy, gx, gy), distance_ss(x2, y1, x2, y2, sx, sy, gx, gy)), 
					min(distance_ss(x1, y1, x2, y1, sx, sy, gx, gy), distance_ss(x1, y2, x2, y2, sx, sy, gx, gy)));
			ans = min(ans, (h >= d ? d : h/2 + d*d/2/h));
		}
		printf("%.6f\n", ans);
	}
	return 0;
}
