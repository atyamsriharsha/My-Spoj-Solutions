#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define gc getchar_unlocked 
typedef struct node
{
	long long int a,b,c ;
}node ;
void scan(long long int &x)
{
	register long long int c  = gc() ; 
	x = 0 ;
	for(;c<47 || c>58;c=gc()) ;
	for(;c>47 && c<58;c=gc())
	{
		x = (x<<1) + (x<<3) + c -48 ;
	}
}
int main()
{
	long long int test,n,i ;
	scan(test);
	while(test--)
	{
		scan(n) ;
		node p[n] ;
		for(i=0;i<n;i++)
		{
			scan(p[i].a) ;
			scan(p[i].b) ;
			scan(p[i].c) ;
		}


	}
	return 0 ;
}