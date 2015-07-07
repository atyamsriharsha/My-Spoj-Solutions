#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std ;
typedef struct array
{
	long long unsigned int oldvalue,newvalue ;
}array;
int main()
{
	int test,n,k ,i,j;
	scanf("%d",&test) ;
	for(j=0;j<test;j++)
	{
		scanf("%d %d",&n,&k) ;
		array a[n] ;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i].oldvalue) ;
			a[i].newvalue = a[i].oldvalue ;
		}
		while(k--)
		{
			a[0].newvalue = (a[n-1].oldvalue)^(a[0].oldvalue)^(a[1].oldvalue) ;
			a[n-1].newvalue =(a[n-2].oldvalue)^(a[0].oldvalue)^(a[n-1].oldvalue); 
			for(i=1;i<n-1;i++)
			{
         		a[i].newvalue = (a[i+1].oldvalue)^(a[i].oldvalue)^(a[i-1].oldvalue) ;
			}
			for(i=0;i<n;i++)
			{
				a[i].oldvalue = a[i].newvalue ;
			}
		}
		for(i=0;i<n-1;i++)
			printf("%lld ",a[i].newvalue);
		printf("%lld\n",a[n-1].newvalue);
	}
	return 0 ;
}