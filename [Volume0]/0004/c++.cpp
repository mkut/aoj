#include <iostream>
using namespace std;

int main()
{
  int a, b, c, d, e, f;
  while(cin >> a >> b >> c >> d >> e >> f)
  {
    double x = (double)(c*e - f*b)/(a*e - b*d);
    double y = (double)(c*d - f*a)/(b*d - a*e);
    if(x  == -0)
    {
      x = +0;
    }
    if(y  == -0)
    {
      y = +0;
    }
    
    printf("%.3f %.3f\n", x, y);
  }
  return 0;
}