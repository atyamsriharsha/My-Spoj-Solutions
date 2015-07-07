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
	cin >> i ;
		int j,a[i],count=0,b=0,c=0 ;
		for(j=0;j<i;j++)
		{
			cin >> a[j] ;
			count= count + a[j] ;
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
				else
				{
					c =c+ b - a[j] ;
				}
			}
			cout << c/2 << endl ;
		}
	return 0 ;
}