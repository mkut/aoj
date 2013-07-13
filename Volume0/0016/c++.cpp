#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
  double x = 0;
  double y = 0;
  int rad = 90;
  string str;
  while(cin >> str)
  {
    int sep = str.find(',', 0);
    int r = atoi(str.substr(0, sep).c_str());
    int t = atoi(str.substr(sep+1, str.length() - sep).c_str());
    if(r == 0 && t == 0)
    {
      break;
    }
    
    x += r * cos(M_PI * rad / 180);
    y += r * sin(M_PI * rad / 180);
    rad -= t;
  }
  cout << (int)x << endl;
  cout << (int)y << endl;
  return 0;
}