#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std ;
static long long int a[1000],b[1000];
void binary(long long int num)
{
 	long long int rem;
 	if(num<=1)
 	{
 		cout << num ;
 		return ;
 	}
    rem = num % 2;
    binary(num/2);
    cout << rem;
}
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		long long int x,y ;
		scanf("%lld %lld",&x,&y) ;
		binary(x) ;
		binary(y) ;
		test-- ;
	}
	return 0 ;
}