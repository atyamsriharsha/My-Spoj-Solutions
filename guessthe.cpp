#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    int rem;
    if(b==0)
    return a;
    if(a==0)
    return b;
    if(b>a)
    {
      a=a+b;
      b=a-b;
      a=a-b;
    }
    rem=a%b;
    while(rem>0)
    {
      a=b;
      b=rem;
      rem=a%b;
    }
    if(rem==0)
      return b;
    else
      return rem;
}                        
int main()
{
    string s ;
    cin >> s ;
    int length = s.length(),i,count =0,num[1000] ;
    for(i=0;i<length;i++)
    {
      if(s[i]=='Y')
      {
        count++ ;
        num[count] = i+1 ;
      }
    }
    int lcm;
    lcm=num[1]*num[2]/gcd(num[1],num[2]);
    for(i=3;i<=count;i++)
        lcm=lcm*num[i]/gcd(lcm,num[i]);            
    cout<<lcm<<endl;        
    return 0;
}
