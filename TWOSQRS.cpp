#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std ;

int a[1000001] ;
void primeFactors(int n)
{
	int temp,count1 = 0 ;
	temp = sqrt(n);
	if(temp*temp==n)
	{
		cout << "Yes" << endl;
		count1 = 1 ;
	}
	if(count1==0)
	{
	int j=0,p,count=1,i;
    for(i=3;i<=sqrt(n);i=i+2)
    {
        while (n%i == 0)
        {
            if(i%4==3)
            {
            	a[j] = i ;
            	j++ ;
            } 
            n = n/i;
        }
    }
    sort(a,a+j) ;
    if(j>=2)
    {
    	for(p=0;p<j;p++)
    	{
    		if(a[p]==a[p+1])
    		{
    			count++ ;
    		}
    		else
    		{
    			if(count%2==0 && count!=0)
    				cout << "Yes" << endl ;
    			else if(count%2!=0)
    			{
    				cout << "No" << endl ;
    				count = 1 ;
    			}
    		}
    	}
	}
	else 
	{
		if(n%4==1)
			cout << "Yes" << endl ;
		else
		cout << "No" << endl ;
	}
}
}
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		int  n ;
		scanf("%d",&n) ;
		if(n==2)
			cout << "Yes" << endl ;
		else
		{
			primeFactors(n) ;
		}
		test-- ;
	}
	cout << endl ;
	return 0 ;
}