#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits.h>
#include <utility>
using namespace std ;
#define gc getchar_unlocked
void scan(int &x)
{
  	register int c  = gc() ;
  	x	= 0 ;
  	for(;(c<48 || c>57);c = gc());
  	for(;c>47 && c<58;c = gc())
  	 {
  	 	x = (x<<1) + (x<<3) + c - 48;
  	 }
}
int main()
{
	int n1,n2,d,i,j,p,q,count=0,flag=0 ;
	scan(n1) ;
	scan(n2) ;
	scan(d) ;
	if(n1==0 && n2==0 && d==0)
		return 0 ;
	int a[n1+1+n2][n1+n2+1] ;
	for(i=1;i<=n1+n2;i++)
	{
		for(j=1;j<=n2+n1;j++)
			a[i][j] = 0 ;
	}
	for(i=0;i<d;i++)
	{
		scan(p) ;
		scan(q) ;
			a[p][q] = 1 ;
		//	a[q][p] = 2 ;
	}
	while(1)
	{
		if(flag==0)
		{
			for(i=1;i<=n1;i++)
			{
      			for(j=1;j<=n1+1+n2;j++)
      			{
                	if(a[i][j]!=1 && a[i][j]!=-1)
                		a[i][j] = -1 ;
      			}
      		}
      		count++ ;
      		for(i=n1+1;i<=n1+n2+1;i++)
			{
      			for(j=1;j<=n1;j++)
      			{
                	if(a[i][j]!=1)
                		a[i][j] = -1 ;
      			}
      		}
      		count++ ;
      	}
      	else
      	{
      		break ;
      	}
      	for(i=1;i<=n1+n2+1;i++)
      	{
      		for(j=1;j<=n1+n2+1;j++)
      		{
      			if(a[i][j]==-1)
      			{
      				flag = 1 ;
      			}
      			else
      				flag = 0 ;
      		}
      	}
	}
	return 0 ;
}