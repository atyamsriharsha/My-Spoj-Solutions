#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
int main()
{
	int test ;
	scanf("%d",&test) ;
	while(test)
	{
		int i =1 ;
		long long r ;
		cin >> r ;
		double ans ;
		ans = double(4*r*r) + 0.25 ;
		printf("Case %d: %.2lf\n",i++,ans);
		test-- ;
	}
	return 0 ;
}