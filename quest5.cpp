#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std ;
typedef struct key
{
	int a ;
	int b ;
}key ;

bool comp(const key &m,const key &n)
{
	return m.b < n.b ;
}
int main()
{
	int test,n,i,start,end ;
	scanf("%d",&test);
	while(test--)
	{
       scanf("%d",&n);
      	key r[n] ;
       for(i=0;i<n;i++)
       {
       	scanf("%d %d",&r[i].a,&r[i].b) ;
       }
       sort(r,r+n,comp) ;
       start = 0 ;
       end = -1 ;
       for(i=0;i<n;i++)
       {
       		if(r[i].a>end)
       		{
       			start++ ;
       			end = r[i].b ;
       		}
       	}
       	printf("%d\n",start );
	}
	return 0 ;
}