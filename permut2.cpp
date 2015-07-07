#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
int main()
{
	int n ,i,a[1000005],b[1000005],flag;
	while(1)
	{
		flag = 0 ;
		scanf("%d",&n) ;
		if(n==0)
			break ;
		else
		{
			int a[n] ;
			for(i=1;i<=n;i++)
			{
				scanf("%d",&a[i]) ;
			}
			for(i=1;i<=n;i++)
			{
				b[a[i]] = i ;
			}
			for(i=1;i<=n;i++)
			{
            	if(a[i]!=b[i])
            		flag =  1 ;
			}
			if(flag)
				cout << "not ambiguous" << endl ;
			else
				cout << "ambiguous" << endl ;
		}
	}
	return 0 ;
}