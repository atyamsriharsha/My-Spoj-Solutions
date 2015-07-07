#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;
int main()
{
	while(1)
	{
		int n ;
		scanf("%d",&n) ;
		if(n==0)
		{
			return 0 ;
		}
		int result = (n*(n+1)*(2*n+1))/6 ;
		printf("%d\n",result);
	}
	return 0 ;
}