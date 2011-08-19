#include <iostream>
#include <vector>
using namespace std;

int calc(vector<char> str)
{
  int num = 0;
  int keta = 1;
  vector<char>::iterator it = str.end()-1;
  
  while(it != str.begin()-1)
  {
    if(*it == '=')
    {
      it--;
    }
    if(*it == '-')
    {
      if(it == str.begin())
      {
        return -num;
      }
      return calc(vector<char>(str.begin(), it)) - num;
    }
    if(*it == '+')
    {
      return calc(vector<char>(str.begin(), it)) + num;
    }
    if(*it == ')')
    {
      vector<char>::iterator tmpit = it-1;
      int nest = 0;
      while(*tmpit != '(' || nest > 0)
      {
        if(*tmpit == ')')
        {
          nest++;
        }
        if(*tmpit == '(')
        {
          nest--;
        }
        tmpit--;
      }
      num = calc(vector<char>(tmpit+1, it));
      it = tmpit-1;
      continue;
    }
    if(*it == '*' || *it == '/')
    {
      vector<char>::iterator tmpit = it-1;
      int nest = 0;
      while((*tmpit != '+' && *tmpit != '-') || nest > 0)
      {
        if(tmpit == str.begin()-1)
        {
          if(*it == '*')
          {
            return calc(vector<char>(tmpit+1, it)) * num;
          }
          else
          {
            return calc(vector<char>(tmpit+1, it)) / num;
          }
        }
        if(*tmpit == ')')
        {
          nest++;
        }
        if(*tmpit == '(')
        {
          nest--;
        }
        tmpit--;
      }
      if(*it == '*')
      {
        num = calc(vector<char>(tmpit+1, it)) * num;
      }
      else
      {
        num = calc(vector<char>(tmpit+1, it)) / num;
      }
      it = tmpit;
      continue;
    }
    num += keta * (*it - '0');
    keta*=10;
    it--;
  }
  return num;
}

int main()
{
  int n;
  cin >> n;
  while(n--)
  {
    char tmp[101];
    cin >> tmp;
    vector<char> str;
    for(char* p = tmp; *p != '\0'; p++)
    {
      str.push_back(*p);
    }
    
    cout << calc(str) << endl;
  }
  return 0;
}