#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
long long int power(long long int a,long long int b)
{
  long long int temp;
    if(b==0)
        return 1;
    temp = power(a,b/2);
    if(b%2==0)
        return temp*temp;
    else
        return a*temp*temp;
}

long long int min(long long int a,long long int b)
{
	return (a<b)?a:b ;
}

long long int exp(int n, int k)
{
    int C[n+1][k+1];
    int i, j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=min(i,k);j++)
        {
            if(j==0||j==i)
                C[i][j] = 1;
            else
                C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

long long int binomial(int n)
{
		int m = exp(2*n,n) ;
	return m ;
}
int main()
{
   int test ;
   scanf("%d",&test) ;
   while(test)
   {
   	long long int a,b,n,p,met ;
    long long int ans ;
   	scanf("%lld %lld %lld",&a,&b,&n) ;
    p =binomial(n) ;
    met = power(p,b) ;
    ans = power(a,met) ;
    cout << ans << endl ; 

   	test-- ;
   }
	return 0 ;
}