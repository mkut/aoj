#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
  int tmp;
  while(cin >> tmp)
  {
    vector<int> numbers;
    numbers.push_back(tmp);
    for(int i = 1; i < 5; i++)
    {
      cin >> tmp;
      numbers.push_back(tmp);
    }
    sort(numbers.begin(), numbers.end(), greater<int>());
    for(vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
      cout << *it << ((it+1) == numbers.end() ? "\n" : " ");
  }
  return 0;
}