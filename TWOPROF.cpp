#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cstring>
#include <new>
#include <queue>
using namespace std ;
#define gc getchar_unlocked

void scanint(long long int &x) 
{
    register long long int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

class interval
{
public:
	long long int start,finish ;
	bool operator < (const interval& x) const
	{
		if(finish!=x.finish)
		{
			return finish<x.finish ;
		}
		return start < x.start ;
	}
};

int main()
{
	long long int test,n,i,count,last_finished;
	scanf("%lld",&test);
	while(test)
	{
		last_finished =0 ;
		count = 2 ;
		scanint(n);
		interval a[n] ;
		for(i=0;i<n;i++)
		{
            scanint(a[i].start) ;
            scanint(a[i].finish) ;
		}
		sort(a,a+n) ;//sorting according to increasing order of finish times
        queue <int> opt ;
        for(i=0,last_finished=0;i<n;i++)
        {
        	if(a[i].start>=last_finished)
        	{
        		opt.push(i) ;
        		last_finished = a[i].finish ;
        	}
        }
        printf("%d\n",opt.size());
		test-- ;
	}
	return 0 ;
}