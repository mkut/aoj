#include <iostream>
using namespace std;

void solve(int n)
{
  long long uriage[4000];
  int id[4000], numid = 0;
  int out[4000], numout = 0;
  for(int i = 0; i < n; i++)
  {
    int tmpid, tmptanka, tmpkazu;
    cin >> tmpid >> tmptanka >> tmpkazu;
    for(int j = 0; ; j++)
    {
      if(j == numid)
      {
        uriage[j] = (long long)tmptanka * tmpkazu;
        id[j] = tmpid;
        numid++;
        if(uriage[j] >= 1000000)
        {
          out[numout++] = tmpid;
        }
          break;
      }
      if(id[j] == tmpid)
      {
        uriage[j] += (long long)tmptanka * tmpkazu;
        if(uriage[j] >= 1000000 && uriage[j] - (long long)tmptanka * tmpkazu < 1000000)
        {
          out[numout++] = tmpid;
        }
        break;
      }
    }
  }
  
  //1000000を超えた順に出力しなければならない
  for(int i = 0; i < numout; i++)
  {
    cout << out[i] << endl;
  }
  if(numout == 0)
  {
    cout << "NA" << endl;
  }
  
  /*
  bool exist = false;
  for(int i = 0; i < numid; i++)
  {
    if(uriage[i] >= 1000000)
    {
      exist = true;
      cout << id[i] << endl;
    }
  }
  if(!exist)
  {
    cout << "NA" << endl;
  }
   */
}

int main()
{
  int n;
  while(cin >> n, n != 0)
  {
    solve(n);
  }
  
  return 0;
}