#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	long long int a,b,c,d,i;
	//scanf("%lld",&d);
	while(scanf("%lld",&a)>0)
	{
		b=0;
		i=a;
		{
			b=b+((i/5)+(i/25)+(i/125)+(i/625)+(i/3125)+(i/15625)+(i/78125)+(i/390625)+(i/1953125)
			+(i/9765625)+(i/48828125)+(i/244140625)+(i/1220703125));
		}
		printf("%lld\n",b);
	}
	return 0 ;
}