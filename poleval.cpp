#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std ;
int ans(int c[],int n,int p)
{
	int i,res=0 ;
	for(i=n;i>0;i--)
    {
		res = (res + c[i])*p ;
    }
    res= res + c[0] ;
	return res ;
}
int main()
{
	int n ,i,k,j=1;
	while(1)
	{
        scanf("%d",&n) ;
		if(n==-1)
			return 0 ;
		int c[n+1] ;
		for(i=n;i>=0;i--)
		{
			scanf("%d",&c[i]) ;
		}
		scanf("%d",&k) ;
		int p[k] ;
		for(i=k-1;i>=0;i--)
		{
			scanf("%d",&p[i]) ;
		}
		cout << "Case " << j <<":"<< endl;
		for(i=k-1;i>=0;i--)
		{
			cout << ans(c,n,p[i]) << endl  ;
		}
		j++ ;
	}
	return 0 ;
}