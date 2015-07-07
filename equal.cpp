#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <new>
using namespace std ;
int main()
{
	int test ;
	cin >> test ;
	for(h=1;h<=test;h++)
	{
		int m,n,k,p,l ;
		cin >> m >>n >> k ;
		int a[m][n],i,j ;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> a[i][j] ;
			}
		}
		cout << "Case" ;
		cout << h ;
		cout << ":" ;
		int max ,count  ;
		for(i=0;i<(m-k+1);i++)
		{
			for(j=0 ;j<(n-k+1);j++)
			{
				count = 0 ;
				max = 0 ;
				for(p=i;p<i+k ;p++)
				{
					for(l=j;l<j+k;l++)
					{
						if(a[p][l]>=max)
						{
							max = a[p][l] ;
							count++;
						}
					}
				}
				if(count>1)
				{
					cout << max << "(" << count << ")" ;
				}
				else
				{
					cout << max ;
				}
			}
		}
	}
	return 0 ;
}