#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
#define max 10000
struct tower
{
	int h,c ;
};

bool operator <(tower a,tower b)
{
	if(a.h==b.h)
		return (a.c)<(b.c) ;
	return (a.h)<(b.h) ;
}
int N ;
tower array[2*max+1] ;
int f(int pos)
{
    int i;
    int cost = 0;
    for(i=0;i<N;++i ) {
        cost = cost + fabs( array[ i ].h - array[ pos ].h ) * array[ i ].c;
    }
    return cost;
}
int main()
{
	int test ;
	int i,hi,lo,l,r,mini,cur;
	cin >> test ;
	while(test)
	{
		scanf("%d",&N) ;
		for(i=0;i<N;++i) 
		{
            scanf("%d",&array[i].h);
        }
        for(i=0;i<N;++i) 
        {
            scanf("%d",&array[i].c);
        }
        lo = 0;
        hi = N - 1;
        sort(array,array+N);
        while(hi-lo+1>3) 
        {
            l = (lo*2+hi)/3;
            r = (lo+hi*2)/ 3;
            if(f(l)<f(r)) 
            {
                hi =r;
            }
            else 
            {
                lo =l;
            }
        }
        mini = f(lo);
        for(i=lo+1;i<=hi;++i) 
        {
            mini = min(mini,f(i));
        }
        printf( "%d\n", mini );
    	test-- ;
	}
	return 0 ;
}