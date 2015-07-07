#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
using namespace std ;
long long int gcd(long long int x,long long int y)
{
	if(y==0)
		return x ;
	return(gcd(y,x%y)) ;
}
int main()
{
	int test ;
	scanf("%d",&test) ;
	while(test)
	{
		long long int n,d,j ;
		scanf("%lld",&n) ;
		if(n>0)
		{
		long long int n2 = n*n,ans ;
		if(n&1)
		{
           ans = (3*n2 +1)/2 ;
		}
		else
		{
			ans = 3*n2/2 ;
		}
		d = 6*n2*n ;
		j = gcd(ans,d) ;
		if(j>0)
		{
		ans /=j ;
		d /= j ;
		}
		printf("%lld/%lld\n",ans,d) ;
		}
		else
		{
			printf("0\n") ;
		}
		test-- ;
	}
	return 0 ;
}