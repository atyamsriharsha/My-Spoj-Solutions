#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std ;
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		int n ;
		cin >> n ;
		int a[n],i,max,index=0,index1,flag=0 ;
		for(i=0;i<n;i++)
			cin >> a[i] ;
		for(i=n-1;i>=0;i--)
		{
			if(i>=1)
			{
				if(a[i]>a[i-1])
				{
					flag=1 ;
                break ;
				}
			}
		}
		if(flag==0)
			cout << "-1" << endl ;
		else if(flag==1)
		{
			max=a[i-1] ;
        	index1 =i ;
        	for(int j=i+1;j<n;j++)
        	{
        		if(a[j]>max && a[j]<a[index1])
        			index1 = j ;
        	}
        	if(i>=1)
        	{
        	swap(a[index1],a[i-1]) ;
        	}
        	sort(a+i,a+n);
			for(i=0;i<n;i++)
				cout << a[i] ;
			cout << endl ;
		}
		test-- ;
	}
	return 0 ;
}