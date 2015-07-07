#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <new>
using namespace std ;
char str[500005] ;
int s[500005] ;
long long length ;

int comp(const void *a,const void *b)
{
	return (strcmp((str+ *((int*)a)),(str+ *((int*)b))));
}

long long lcp()
{
	int i, j, k;
	long long count = 0;
	char *z = str, *y = str;
	int p[50005] = {0};
	for(i=1,k=0;i<length;i++,k=0) 
	{
		z = str + s[i];
		y = str + s[i-1];
		while(*z==*y) 
		{
			p[i]++;
			z++;
			y++;
		}
		count += p[i];
	}
	return count;
}
void suffixarray(int n)
{
	int i ;
	for(i=0;i<n;i++)
	{
		s[i] = i ;
	}
	qsort(s,n,sizeof(int),comp) ;
}
int main()
{
	int test,c ;
	scanf("%d",&test) ;
	while(test--)
	{
		scanf("%s",str) ;
		length = strlen(str) ;
 		suffixarray(length) ;
        c = lcp() ;
        printf("%lld\n",length*(length+1)/2 - c);

	}

	return 0 ;
}