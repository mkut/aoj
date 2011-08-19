#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    
    a *= a;
    b *= b;
    c *= c;
    
    int max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    if(a + b + c - max - max == 0)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}