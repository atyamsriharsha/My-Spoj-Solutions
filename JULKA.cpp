#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;
long long int multiple(long long int a, long long int b)
{

  if(b==0)
  {  //Base case a * 0 =0
      return 0 ;
  }
  long long int ret = multiple(a,b>>1) ;  //Multiply a by (b>>1).
  ret = (ret+ret)  ; //we double the value of ret i. 2 * (a * (b>>1)). Take MOD in this step
  if(b&1)
  {  
     ret = (ret + a) ;
  }
   return ret ;
}
int main()
{
	int n  ;
	scanf("%d",&n);
	while(n)
	{
		long long int a,b,p ;
		cin >> a>>b ;
		p=multiple(a,b) ;
		cout << p << endl;
		n-- ;
	}
	return 0 ;
}