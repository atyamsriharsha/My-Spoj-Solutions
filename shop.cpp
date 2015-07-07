#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;
int main()
{
	while(1)
	{
		int h,w ;
		cin >> h >> w ;
		char a[h][w] ;
		if(h==0 && w==0)
			return 0 ;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin >> a[i][j];
			}
		}
	}
	return 0 ;
}