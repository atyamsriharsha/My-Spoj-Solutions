#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long gcd(long a,long b)
{
   if(b==0)
    return a ;
    return gcd(b,a%b);
}
int main()
{
 int test,count,i,flag;
 scanf("%d",&test);
 while(test)
 {
    string s;
    cin>>s;
    long number=1,frac;
    count=0;
    flag=0;
    for(i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='.')
      {
        flag=1;
        break;
      }
      else
        count++;
    }
    for(i=0;i<s.size();i++)
    {
      if(s[i]!='.')
      {
        number=number*10 + (s[i]-48);
      }
    }
    frac=1;
    if(flag!=0)
    {
      frac=pow(10,count);
    }
      printf("%ld\n",frac/gcd(number,frac));
      test-- ;
  }
  return 0;
}