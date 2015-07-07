#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define GI ({int i;scanf("%d",&i);i;})
using namespace std;
bool visited[1002],primes[int(1e6)+1] ;
int toprint[1002],m,n,d ;

bool isprime(int n)
{
	if(n==1 || n==2)
		return true ;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false ;
	}
	return true ;
}

void sieve()
{
	for(int i = 1;i<=int(1e6);i++)
	{
		primes[i] = isprime(i);
	}
}

bool go(int pos)
{
	int j,i ;
	if(pos==m-n+1)
		return true ;
	for(i=n;i<=m;i++)
		if(visited[i]==0)
		{
			int s=i,p=1 ;
			for(j=1;j<d;j++)
              if(pos>=j)
              {
              	s+=toprint[pos-j];
              	if(primes[s]!=0)
              	{
              		p=0;
              		break ;
              	}
              }
            if(p!=0)
            {
              	toprint[pos] = i ;
              	visited[i] = true ;
              	if(go(pos+1)!=0)
              		return true;
              	visited[i] = false ;
            }
		}
	return false ;
}
int main()
{
	sieve() ;
	int i ;
	while(1)
	{
		scanf("%d%d%d",&n,&m,&d);
		//n = GI,m=GI,d=GI ;
		if(n==0)
			return 0 ;
		memset(visited,0,sizeof(visited));
		bool flag = false ;
		for(i=n;i<=m;i++)
		{
              visited[i] = 1 ;
              toprint[0] = i ;
              if(go(1)!=0)
              {
              	flag = true ;
              	break ;
              }
              visited[i] = 0 ;
		}
		if(flag!=0)
		{
			for(i=n;i<=m;i++)
			{
				if(i-n)
				{
					printf(",");
				}
				printf("%d",toprint[i-n]);
				visited[toprint[i-n]] = 0 ;
			}
		}
		else
		{
			printf("No anti-prime sequence exists.");
		}
		printf("\n");
	}
	return 0 ;
}