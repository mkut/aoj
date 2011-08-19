#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    //2*(x2-x1)X + 2*(y2-y1)Y = x2^2-x1^2 + y2^2-y1^2
    //2*(x3-x1)X + 2*(y3-y1)Y = x3^2-x1^2 + y3^2-y1^2
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = 2*(x2-x1);
    double b = 2*(y2-y1);
    double c = x2*x2 - x1*x1 + y2*y2 - y1*y1;
    double d = 2*(x3-x1);
    double e = 2*(y3-y1);
    double f = x3*x3 - x1*x1 + y3*y3 - y1*y1;
    
    double x = (c*e - f*b)/(a*e - b*d);
    double y = (c*d - f*a)/(b*d - a*e);
    if(x  == -0)
    {
      x = +0;
    }
    if(y  == -0)
    {
      y = +0;
    }
    
    printf("%.3f %.3f %.3f\n", x, y, pow((x-x1)*(x-x1) + (y-y1)*(y-y1), 0.5));
  }
  return 0;
}