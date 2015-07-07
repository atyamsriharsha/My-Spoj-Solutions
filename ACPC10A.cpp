#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std ;
int main()
{
	int a,b,c ;
	while(1)
	{
	scanf("%d %d %d",&a,&b,&c) ;
	if(a==0 && b==0 && c==0)
		return 0 ;
	if(2*b==a+c)
		printf("AP %d\n",(2*c)-b) ;
	if(b*b == a*c)
		printf("GP %d\n",c*c/b) ;
	}
	return 0 ;
}