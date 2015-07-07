#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
int main(int argc, char const *argv[])
{
    
    int test,i ;
    scanf("%d",&test) ;
    while(test)
    {
    	int n,u ;
    	scanf("%d %d",&n,&u) ;
    	int a[n] ;
    	for(i=0;i<n;i++)
    		a[i]=0 ;
    	while(u)
    	{
    		int l,r,val ;
    		scanf("%d %d %d",&l,&r,&val) ;
    		for(i=l;i<=r;i++)
    			a[i]=a[i]+val ;
          u -- ;
    	}
    	int q ;
    	scanf("%d",&q) ;
    	while(q)
    	{
    		int q1 ;
    		cin >> q1 ;
    		printf("%d\n",a[q1]) ;
    		q-- ;
    	}
    	test-- ;
    } 
	return 0;
}
