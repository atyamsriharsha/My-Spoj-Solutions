#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
int main()
{
	long long int test ;
	scanf("%lld",&test);
	long long int sum,n,i,a[1000005],res1,res ;
	while(test)
	{
		sum = 0 ;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]) ;
		}
		for(i=0;i<n;i++)
		{
              if(a[i]<0)
              {
              	sum = max(sum + a[i]*2,sum + a[i]*(i+1)) ;
              }
              else
              {
              	sum = sum + a[i]*(i+1) ;
              }
			
		}
		printf("%lld\n",sum);
		test-- ;
	}
	return 0 ;
}
