#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <assert.h>
#include <complex.h>
#include <ctype.h> 
#include <limits.h>
#include <signal.h>
#include <ctype.h>
#include <errno.h>
using namespace std ;
long long int pow(long long int a,long long int b,long long int MOD)
{
	long long int x=1,y=a; 
	while(b>0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>MOD)
			 x%=MOD;
		}
		y = (y*y);
		if(y>MOD) 
			y%=MOD; 
		b /= 2;
	}
	return x;
}
long long int InverseEuler(long long int n,long long int MOD)
{
	return pow(n,MOD-2,MOD);
}

long long int C(long long int n,long long int r,long long int MOD)
{
	long long int i ;
	vector<long long int> f(n,1);
	for (i=2; i<=n;i++)
	f[i]= (f[i-1]*i) % MOD;
	return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
int main()
{
	int test ;
	scanf("%d",&test);
	long long int a,b,n,p,i,sum=0,ans,mod =pow(10,9)+7;
	while(test)
	{
		sum = 0 ;
		scanf("%lld%lld%lld",&a,&b,&n) ;
		for(i=0;i<n;i++)
		{
			p = C(n,i,mod) ;
			sum = sum +p*p ;
		}
        ans = pow(a,pow(sum,b,mod),mod) ;
        printf("%lld\n",ans%mod);
		test-- ;
	}
	return 0 ;
}