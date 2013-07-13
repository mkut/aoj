#include <iostream>
using namespace std;

int main()
{
  int x, y, z;
  while(cin >> x >> y >> z, z != 0)
  {
    int max = x > y ? (x > z ? x : z) : (y > z ? y : z);
    int n;
    cin >> n;
    while(n--)
    {
      int r;
      cin >> r;
      if(r*r * 4 > x*x +y*y + z*z - max*max)
      {
        cout << "OK" << endl;
      }
      else
      {
        cout << "NA" << endl;
      }
    }
  }
  
  return 0;
}