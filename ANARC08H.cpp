#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std ;

long long int josephus(long long int n,long long int k)
{
  long long int a=1,i;
    for(i=1;i<=n;i++)
        a=(a+k-1)%i+1;
    return a;
}
int main()
{
	long long int n,d,p,m ;
	while(1)
	{
		scanf("%lld %lld",&n,&d);
		m= josephus(n,d);
		cout << m;
	}
}