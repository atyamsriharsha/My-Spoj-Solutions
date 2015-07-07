#include <iostream>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std ;
typedef struct frog
{
	int x,y ;
}frog;

int comparex(const void *a,const void *b)
{
	frog *p1 = (frog *)a,*p2= (frog *)b ;
	return (p1->x - p2->x) ;
}

int comparey(const void *a,const void *b)
{
	frog *p1 = (frog *)a,*p2 = (frog *)b ;
	return (p1->y - p2->y) ;
}

int main()
{
	int test,n,k,i ;
	cin >> test ;
	while(test--)
	{
		cin >> n >> k;
		frog frogs[k] ;
		int a[k],b[k] ;
		for(i=0;i<k;i++)
		{
			cin >> frogs[i].x ;
			cin >> frogs[i].y ;
		} 
		qsort(frogs,k,sizeof(frog),comparex) ;
		for(i=0;i<k;i++)
		{
			a[i] = frogs[i].x ;
		}
		qsort(frogs,k,sizeof(frog),comparey) ;
		for(i=0;i<k;i++)
		{
			b[i] = frogs[i].y ;
		}


	}

	return 0 ;
}