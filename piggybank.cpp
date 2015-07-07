#include <iostream>
#include <algorithm>
#include <string> 
using namespace std; 
const int INT_MAX =1000000 ;
static int p[510],w[510],m[10010];
int main()
{
  int test, n, e, f,i,j,tmp,tmp1;
  cin>>test;
  while(test)
  {
       cin>>e>>f;
       cin>>n;
       tmp = INT_MAX;
    for(i=1;i<=n;i++) 
    {
      cin>>p[i]>>w[i];
      tmp = min(tmp, w[i]);
    }
    for(i=0;i<tmp;i++)
    { 
      m[i]=0;
    }
    for(i=tmp;i<=f-e;i++) 
    {
      tmp = INT_MAX;
      for(j=1;j<=n;j++) 
      {
	      tmp1 = 0;
	      if(i >= w[j])
	      if(m[i-w[j]] > 0 || i == w[j]) tmp1 = p[j] + m[i-w[j]];
	      if(tmp1 < tmp && tmp1!=0)
        {
         tmp = tmp1;
        }
      }
      if(tmp==INT_MAX)
      { 
        m[i] = 0;
      }
      else 
      {
          m[i] = tmp;
      }
    }
      if(m[f-e]==0)
      cout<<"This is impossible."<<"\n";
      else
      cout<<"The minimum amount of money in the piggy-bank is "<< m[f-e] <<"."<<"\n";
    test-- ;
  }
  return 0;
}