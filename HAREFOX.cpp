#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;

int main ()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		double a,b,c,d,h,f,nextH,nextF;
		cin >> a >> b >> c >> d >> h >> f;
		int nH[2], nF[2];
		nH[0]=0; nH[1]=0; nF[0]=0; nF[1]=0;
		for (int k=0;k<20;++k)
		{
			nextH=a*h-b*f;
			nextF=c*f+d*h;
			if (nextH > h) // its increasing
				++nH[0];
			else if (nextH < h) // decreasing
				++nH[1];
			if (nextF > f) // its increasing
				++nF[0];
			else if (nextF < f) // decreasing
				++nF[1];
			h=nextH;
			f=nextF;
		}
		if(nextH< 0.5 && nextH > -0.5 && nextF < 0.5 && nextF > -0.5)
			cout << "Ecological balance will develop." << endl;
		else if(nH[0]+5<nH[1] && nF[0]> nF[1]+5)
			cout << "Hares will die out while foxes will overgrow." << endl;
		else if(nH[0]>nH[1]+5 && nF[0]+5 < nF[1])
			cout << "Hares will overgrow while foxes will die out." << endl;
		else if(nH[0]+5<nH[1] && nF[0]+5 < nF[1])
			cout << "Both hares and foxes will die out." << endl;
		else if(nH[0]> 5+nH[1] && nF[0]> 5+nF[1])
			cout << "Both hares and foxes will overgrow." << endl;
		else
			cout << "Chaos will develop." << endl;
	}
	return 0 ;
}