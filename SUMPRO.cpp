#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define gc getchar_unlocked 

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scan(long long int &x)
{
        register long long int c = gc() ;
        x = 0 ;
        for(;(c<48 || c>57);c=gc()); 
        for(;c>47 && c<58;c= gc())
        {
           x = (x<<1) + (x<<3) + c - 48 ;
        }
}
void scan1(long long unsigned int &x)
{
        register long long unsigned int c = gc() ;
        x = 0 ;
        for(;(c<48 || c>57);c=gc()) ;
        for(;c>47 && c<58;c= gc())
        {
            x = (x<<1) + (x<<3) + c - 48 ;
        }
}
int main()
{
	long long int test;
        long long unsigned int n,sum,a,b,i ; 
        scan(test) ;
        while(test)
        {
                sum = 0 ;
                scan1(n);
             //   printf("%lld\n",i);
              //  cout << n << endl ;
                for(i=1;i<=n/2;i++)
                {
                  //  printf("hello..\n");
                    a = n/i ;
                    //cout << a << endl;
                    sum =sum + i*a ;
                }
                //if(n%2==0)
                //{
                 //       sum = sum + (3*n*n)/4 + n/2 ;
               // }
                cout << (sum%1000000007) << endl ;
                test-- ;
        }
	return 0 ;
}
