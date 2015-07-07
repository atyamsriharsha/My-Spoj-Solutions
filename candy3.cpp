#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std ;
int main()
{
	long long int test ;
	scanf("%lld",&test);
	while(test)
	{
		long long int n,m ;
		scanf("%lld",&n) ;
		m=n;
		long long int a[n],i=0,sum=0 ;
		while(m)
		{
			scanf("%lld",&a[i]) ;
			sum+=a[i] ;
			m-- ;
		}
		if(sum%n==0)
		{
			long long int count = sum/n ,p=0;
			for(i=0;i<n;i++)
			{
                if(a[i]>count)
                {
                   p = p+a[i]-count ;
                }
			}
			printf("%lld\n",p);
		}
		else
		{
			printf("-1\n");
		}
		test-- ;
	}
	return 0 ;
}