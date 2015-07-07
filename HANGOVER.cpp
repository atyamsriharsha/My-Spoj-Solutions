#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;
int main()
{
    float a[275];
    int i;
    for(i=0;i<275;i++)     //precomputes 1/i, not really necessary
    {
        a[i]=1.0/(2.0+i);
    }
    float test;
    //scanf("%f",&test);
    while(1)
    {
        scanf("%f",&test);
        if(test==0)
            return 0 ;
        float result=0;
        for(i=0;i<275;i++)
         {
             result+=a[i];
             if(result>=test)
                break;
        }
        printf("%d card(s)\n",i+1);
       // scanf("%f",&test);
    }
    return 0;
}