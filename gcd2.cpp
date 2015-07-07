#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std ;
int gcd(int a,int b)
{
	if (b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	int  test ,a,n2,i;
	char b[251] ;
	cin >> test ;
	while(test--)
	{
        scanf("%d%s",&a,b) ;
        if(!a)
		{
			printf("%s\n",b);
			continue;
		}
		for(i=n2=0;b[i];i++)
			n2 = (n2*10+b[i]-'0')%a;
		printf("%d\n",gcd(a,n2));

	}
	return 0 ;
}