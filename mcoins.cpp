#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
#define gc getchar_unlocked
int w[1000001] ;
void scan(int &x)
{
	register int c = gc() ;
	x =0 ;
	for(;c<48 || c>57;c=gc()) ;
	for(;c>=48 && c<=57;c=gc())
	{
		x = x<<1 + x<<3 + c - 48 ;
	}
}
int main()
{
	int k,l,m,i ,max1=0;
	scan(k) ;
	scan(l) ;
	scan(m) ;
	int n[m] ;
	for(i=0;i<m;i++)
	{
		scan(n[i]) ;
		max1 = max(max1,n[i]) ;
	}
    w[0] =  0 ;
    for(i=1;i<=max1;++i)
    {
        w[i] = !w[i-1];
        if(i >= k && !w[i-k])
         w[i] = 1;
        if(i >= l && !w[i-l]) 
        	w[i] = 1;
    }
    for(i=0;i<m;++i)
    {
        if(w[n[i]]) 
        	putchar('A');
        else
         putchar('B');
    }
    putchar('\n');
	return 0 ;
}