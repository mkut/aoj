#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  char tmp[32];
  int tmppage;
  
  vector<string> words;
  vector<string>::iterator wordsi;
  vector<vector<int> > pages;
  vector<vector<int> >::iterator pagesi;
  vector<int>::iterator pagesi2;
  
  while(cin >> tmp >> tmppage)
  {
    wordsi = words.begin();
    pagesi = pages.begin();
    while(true)
    {
      if(wordsi == words.end())
      {
        words.insert(wordsi, tmp);
        pages.insert(pagesi, vector<int>(1, tmppage));
        break;
      }
      if(tmp == *wordsi)
      {
        pagesi2 = (*pagesi).begin();
        while(pagesi2 != (*pagesi).end())
        {
          if(tmppage < *pagesi2)
          {
            break;
          }
          pagesi2++;
        }
        (*pagesi).insert(pagesi2, tmppage);
        break;
      }
      if(tmp < *wordsi)
      {
        words.insert(wordsi, tmp);
        pages.insert(pagesi, vector<int>(1, tmppage));
        break;
      }
      wordsi++;
      pagesi++;
    }
  }
  
  wordsi = words.begin();
  pagesi = pages.begin();
  while(wordsi != words.end())
  {
    cout << *wordsi << endl;
    pagesi2 = (*pagesi).begin();
    while(pagesi2 != (*pagesi).end())
    {
      cout << *pagesi2;
      pagesi2++;
      if(pagesi2 != (*pagesi).end())
      {
        cout << " ";
      }
    }
    cout << endl;
    wordsi++;
    pagesi++;
  }
  
  return 0;
}