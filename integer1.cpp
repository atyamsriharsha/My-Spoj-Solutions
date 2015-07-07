#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std ;
vector<long long int > vx,vy ,ret;
int main()
{
	long long int t,k,i,n ;
	double sum1,sum2,sum ;
	while(1)
	{
		vx.clear() ;
		vy.clear() ;
		ret.clear() ;
		sum1 = 0 ;
		sum2 = 0 ;
		cin >> t ;
		if(t==-1)
			return 0 ;
		for(i=0;i<t;i++)
		{
			scanf("%lld",&k) ;
			vx.push_back(k) ;
		}
		for(i=0;i<t;i++)
		{
			scanf("%lld",&k) ;
			vy.push_back(k) ;
		}
		vx.push_back(vx[0]);
        vx.push_back(vx[t-1]);
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        n=t+2;
        for(int i=0;i<n;i++)ret.push_back(vx[(n+i-1)%n]-vx[(i+1)%n]);
        ret.erase(ret.begin(),ret.begin()+1);
        ret.erase(ret.end()-1,ret.end());
        sort(ret.begin(),ret.end());  
        for(int i=0;i<t;i++) sum1+=ret[i]*vy[i];
        sort(ret.rbegin(),ret.rend());
        for(int i=0;i<t;i++) sum2+=ret[i]*vy[i];
        sum=max(fabs(sum1),fabs(sum2))*0.5;
             printf("%.1lf\n",sum);
	}
	return 0 ;
}