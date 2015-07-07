#include<cstdio>
#include<iostream>
#include<cmath>
#define max  1000000
using namespace std;
long long ans[1000010]  ;
long long  ret[1000010];
void answer()
{
  int i,j ;
 for(i=1;i<=max;i++)
  ans[i]=i;
 for(i=2;i<=max;i++)
    if(ans[i]==i)
        for(j=2*i;j<=max;j+=i) 
          ans[j] -= ans[j]/i ;
  for(i=2;i<=max;i++) 
    if(ans[i]==i) 
            ans[i] = i-1;
	for(i=1;i<=max;i++)
    for(j=i;j<=max;j+=i)
      ret[j]+= i*ans[i];
}
int main()
{
  answer();
  int n,t,i,sqt;
  long long sum;
  scanf("%d",&t) ;
  for(i=0;i<t;i++)
  {
    scanf("%d",&n);
    sum = (1+ret[n])*n/2;
    printf("%lld\n",sum);
  }
  return 0 ;
}
