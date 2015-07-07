#include <iostream>
#include <math.h>
#include <cstdio>
#include <algorithm>
using namespace std;
bool prime[50000000]={false};
long store[50000000];
int main()
{
    long long int n;
    n=100000000;
    long long int len=(long long int)sqrt(n);
    long long int max=n/2,y=len/2;
    for(long long int i=1;i<=y;i++)
    {
            if(!prime[i])
            for(long long int j=3*i+1;j<=max;j+=2*i+1)
            {
                    prime[j]=true;
            }
            
    }
    long long int r=0;
    for(long long int j=0;j<=max;j++)
    if(!prime[j])
    {
        store[r++]=2*j+1;
    }
    long long int num;
    scanf("%lld",&num);
    while(num!=0)
    {
        long long int start=0,end=r-1,mid,k;
        mid=(start+end)/2;
        while(store[start]!=store[mid])
        {
            if(store[mid]>num)
                end=mid;
            else
                start=mid;
            mid=(start+end)/2;
        }
        k=start;
        if(num>=2)
            k++;
        double ans=((k-(num/(double)log(num)))/k)*100;
        if(ans<0)
            ans=ans*-1;
        printf("%.1lf\n",ans);
        scanf("%lld",&num);
    }
    return 0;
}
