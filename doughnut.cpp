#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std ;
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		int c,k,w ;
		scanf("%d %d %d",&c,&k,&w) ;
		if(k>=c*w)
			printf("yes\n") ;
		else
			printf("no\n");
		test -- ;
	}
	return 0 ;
}