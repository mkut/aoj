#include <iostream>
#include <math.h>
using namespace std;

inline double size_v(double x, double y)
{
	return sqrt(x * x + y * y);
}

inline bool left_vv(double startx, double starty, double x, double y)
{
	return startx*y - starty*x >= 0;
}

inline bool forward_vv(double x1, double y1, double x2, double y2)
{
	return x1*x2 + y1*y2 >= 0;
}

inline double distance_lp(double x1, double y1, double x2, double y2, double x, double y)
{
	return fabs((y-y1)*(x2-x1) - (x-x1)*(y2-y1)) / size_v(x1-x2, y1-y2);
}

inline bool innertri(double* x, double* y, double cx, double cy)
{
	return left_vv(x[1]-x[0], y[1]-y[0], cx-x[0], cy-y[0]) == left_vv(x[2]-x[1], y[2]-y[1], cx-x[1], cy-y[1])
	&& left_vv(x[1]-x[0], y[1]-y[0], cx-x[0], cy-y[0]) == left_vv(x[0]-x[2], y[0]-y[2], cx-x[2], cy-y[2]);
}
inline bool crosstri_eq(double* x, double* y, double cx, double cy, double cr)
{
	return distance_lp(x[0], y[0], x[1], y[1], cx, cy) < cr || distance_lp(x[1], y[1], x[2], y[2], cx, cy) < cr || distance_lp(x[2], y[2], x[0], y[0], cx, cy) < cr;
}

int main()
{
	double x[3], y[3];
	double cx, cy, cr;
	while(cin >> x[0] >> y[0], x[0] != 0 || y[0] != 0)
	{
		cin >> x[1] >> y[1] >> x[2] >> y[2];
		cin >> cx >> cy >> cr;
		
		//cout << "innertri : " << innertri(x, y, cx, cy) << endl;
		//cout << "crosstri_eq : " << crosstri_eq(x, y, cx, cy, cr) << endl;
		//cout << "size_v : " << size_v(x[0]-cx, y[0]-cy) << "," << size_v(x[1]-cx, y[1]-cy) << "," << size_v(x[2]-cx, y[2]-cy) << endl;
		//cout << "distance_lp : " << distance_lp(x[0], y[0], x[1], y[1], cx, cy) << "," << distance_lp(x[1], y[1], x[2], y[2], cx, cy) << "," << distance_lp(x[2], y[2], x[0], y[0], cx, cy) << endl;
		
		if(innertri(x, y, cx, cy) && !crosstri_eq(x, y, cx, cy, cr))
		{
			cout << 'a' << endl;
		}
		else if(size_v(x[0]-cx, y[0]-cy) <= cr && size_v(x[1]-cx, y[1]-cy) <= cr && size_v(x[2]-cx, y[2]-cy) <= cr)
		{
			cout << 'b' << endl;
		}
		else if(distance_lp(x[0], y[0], x[1], y[1], cx, cy) <= cr && forward_vv(x[1]-x[0], y[1]-y[0], cx-x[0], cy-y[0]) && forward_vv(x[0]-x[1], y[0]-y[1], cx-x[1], cy-y[1])
				|| distance_lp(x[1], y[1], x[2], y[2], cx, cy) <= cr && forward_vv(x[2]-x[1], y[2]-y[1], cx-x[1], cy-y[1]) && forward_vv(x[1]-x[2], y[1]-y[2], cx-x[2], cy-y[2])
				|| distance_lp(x[2], y[2], x[0], y[0], cx, cy) <= cr && forward_vv(x[0]-x[2], y[0]-y[2], cx-x[2], cy-y[2]) && forward_vv(x[2]-x[0], y[2]-y[0], cx-x[0], cy-y[0])
				|| size_v(x[0]-cx, y[0]-cy) <= cr || size_v(x[1]-cx, y[1]-cy) <= cr || size_v(x[2]-cx, y[2]-cy) <= cr)
		{
			cout << 'c' << endl;
		}
		else
		{
			cout << 'd' << endl;
		}
	}
	return 0;
}