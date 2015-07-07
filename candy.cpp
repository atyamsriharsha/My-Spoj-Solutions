#include <iostream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std ;
int main()
{
	int i ;
	while(1)
	{
		cin >> i ;
		if(i==-1)
			return 0 ;
		long long int j,a[i],count=0,b=0,c=0 ;
		for(j=0;j<i;j++)
		{
			cin >> a[j] ;
			(count%i)= ((count%i) + (a[j]%i))%i ;
		}
		if(count%i!=0)
			cout << "-1" << endl ;
		else 
		{
			b = count/i ;
			for(j=0;j<i;j++)
			{
				if(a[j]>b)
				{
					c=c+ a[j]-b ;
				}
			}
			cout << c << endl ;
		}
	}
	return 0 ;
}