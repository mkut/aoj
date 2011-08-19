#include <iostream>
using namespace std;

int gcd(int x, int y)
{
  return x % y == 0 ? y : gcd(y, x%y);
}
int lcm(int x, int y)
{
  return (long long)x * y / gcd(x, y);
}

int main()
{
  int x, y;
  while(cin >> x >> y)
  {
    cout << gcd(x, y) << " " << lcm(x, y) << endl;
  }
  
  return 0;
}