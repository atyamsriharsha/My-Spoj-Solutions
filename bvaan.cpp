#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
int max(int a,int b)
{
	return (a>b?a:b) ;
}

int res(char a[],char b[],int k,int m,int n)
{
	if(k=0)
		return 0 ;
	if(a[m] == b[n])
	{
		res(a,b,k,m,n) = max(res(a,b,k,m,n),res(a,b,k-1,m-1,n-1)) + a[m] ;
	}
	res(a,b,k,m,n) = max(res(a,b,k,m,n),max(res(a,b,k,m-1,n),res(a,b,k,m,n-1))) ;
	return res(a,b,k,m,n) ;

}
int main()
{
	int test ,k,ans,m,n;
	char a[102],b[102] ;
	cin >> test ;
	while(test--)
	{
       cin >> a >> b >> k ;
        m = strlen(a) ;
        n = strlen(b);
       ans = res(a,b,k,m,n) ;
	}
	return 0 ;
}