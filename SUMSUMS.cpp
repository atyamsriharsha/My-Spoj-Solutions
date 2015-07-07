#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	long long int n,t,i=0,sum=0,j=0;
	scanf("%lld %lld",&n,&t) ;
	long long int a[n],b[n];
	for(i=0;i<n;i++)
	{
         scanf("%lld",&a[i]) ;
         sum =(sum+a[i]+98765431)%98765431 ;
	}
	while(t)
	{
		for(i=0;i<n;i++)
		{
       		b[i] = (sum - a[i]+98765431)%98765431 ;
       		a[i] = b[i] ;
       	}
       	sum= 0 ;
       	for(i=0;i<n;i++)
		{
         	sum =(sum + a[i]+98765431)%98765431 ;
		}
       t-- ;
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",(a[i]%98765431));
	}
	return 0 ;
}