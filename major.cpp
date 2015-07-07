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
		int n,i ;
		scanf("%d",&n) ;
		int a[n] ;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int h,flag=1 ;
		h = a[0] ;
		for(i=1;i<n;i++)
		{
			if(h==a[i])
				flag++ ;
			else
			{
				if(flag==1)
					h = a[i] ;
				else
				{
					flag-- ;
				}
			}
		}
		 flag=0;  
            for(i=0; i<n; i++)  
            {  
            if(a[i] == h)  
            flag++;  
            }  
             if(flag > n/2) 
            printf("YES %d\n", h);  
              else  
            printf("NO\n"); 
        printf("\n");
		test-- ;
	}
	return 0 ;
}