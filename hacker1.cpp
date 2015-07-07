#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std ;
static int flag = 0 ;
static  unsigned char BitsSetTable256[256] = 
{
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
    B6(0), B6(1), B6(1), B6(2)
};
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		unsigned int v,c; 
		cin >> v ;
		int  k ;
		cin >> k ;
		int p = v;
		if(v%2==0)
			v= v-1 ;
		while(p>0)
		{
			c = BitsSetTable256[v & 0xff] + BitsSetTable256[(v >> 8) & 0xff] + BitsSetTable256[(v >> 16) & 0xff] + BitsSetTable256[v >> 24]; 
 			for(int i=0;i<256;i++)
			{
  				BitsSetTable256[i] =(i&1)+BitsSetTable256[i/2];
			}
			if(c<=k)
			{
				cout << v << endl;
				flag= 1 ;
				p = 0 ;
			}
			else if(c>k)
				v = v-2 ;
		}
		if(flag==0)
			cout << "-1" << endl ;
		test -- ;
	}
	return 0 ;
}