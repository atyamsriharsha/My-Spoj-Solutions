#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;

double getdistance(int x1,int y1,int x2,int y2)
{
	return sqrt(((double)x1-x2)*(x1-x2) +(y1-y2)*((double)y1-y2));
} 
double min(double a,double b)
{
    if(a>b)
        return b;
    return a;

}
double max(double a, double b)
{
    if(a>b)
        return a;
    return b;
}
int main(int argc, char const *argv[])
{
	int test ;
	scanf("%d",&test);
	while(test)
	{
		int n ;
		scanf("%d",&n);
		int x[n],y[n],i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x[i],&y[i]) ;
		}
		double maxrad=0,minrad=1 ;
		double pointRad =1000000;
		int cond = 1 ;
		for(i=0;i<n && cond==1;++i)
        {
            pointRad =1000000;
            for(j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                double dist = getdistance(x[i],y[i],x[j],y[j]);
                if(dist<2*minrad)
                {
                    cond = 0;
                    break;
                }
                double presentRad  = dist-minrad;
                pointRad = min(pointRad,presentRad);

            }
            maxrad = max(maxrad,pointRad);
        }
        if(cond!=0)
        {
        	printf("%.6lf\n",maxrad);
        }
        else
        {
        	printf("-1.000000\n");
        }

		test-- ;
	}
	return 0;
}