#include <iostream>
using namespace std;

bool left_vector(double startx, double starty, double x, double y)
{
	return startx*y - starty*x > 0;
}
bool right_vector(double startx, double starty, double x, double y)
{
	return startx*y - starty*x < 0;
}
bool inner_triangle(double x, double y, double p1x, double p1y, double p2x, double p2y, double p3x, double p3y)
{
	if(left_vector(p2x-p1x, p2y-p1y, x-p1x, y-p1y) == right_vector(p2x-p1x, p2y-p1y, x-p1x, y-p1y)) return false;
	if(left_vector(p3x-p2x, p3y-p2y, x-p2x, y-p2y) == right_vector(p3x-p2x, p3y-p2y, x-p2x, y-p2y)) return false;
	if(left_vector(p1x-p3x, p1y-p3y, x-p3x, y-p3y) == right_vector(p1x-p3x, p1y-p3y, x-p3x, y-p3y)) return false;
	return left_vector(p2x-p1x, p2y-p1y, x-p1x, y-p1y) == left_vector(p3x-p2x, p3y-p2y, x-p2x, y-p2y) && left_vector(p2x-p1x, p2y-p1y, x-p1x, y-p1y) == left_vector(p1x-p3x, p1y-p3y, x-p3x, y-p3y);
}

int main()
{
	double x1, y1, x2, y2 ,x3 ,y3, xp, yp;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp)
	{
		cout << (inner_triangle(xp, yp ,x1, y1, x2, y2, x3, y3) ? "YES" : "NO") << endl;
	}
	return 0;
}