#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std ;
#define gc getchar_unlocked

void scan(long long int &x)
{
	register long long int c = gc() ;
	x = 0;
	for(;c<48 || c>57;c=gc())
	for(;c>=48 && c<=57;c=gc())
	{
		x = x<<1 + x<<3 + c -48 ;
	}
}
int main()
{
	long long int test,x,y,m,i,j,u,v ;
	scan(test);
	while(test--)
	{
		scan(x) ;
		scan(y) ;
		long long int a[x][y];
		for(i=0;i<x;i++)
		{
			for(j=0;j<y;j++)
			{
				a[i][j] = 0 ;
			}
		}
		scan(m) ;
		for(i=0;i<m;i++)
		{
           scan(u) ;
           scan(v) ;
           a[u][v] = 1 ;
		}

	}

	return 0 ;
}