#include <iostream>
#include <cmath>
#include <string>
using namespace std ;
int main()
{
	int i =10 ;
	while(i)
	{
		string s1,s2 ;
		cin >> s1 >>s2 ;
		int length1 ,length2;
		length1 = s1.length() ;
		length2 = s2.length() ;
		int m=length1,n=length2 ;
        int a[length1] ,k=0;
        for(int j=0;j<length1;j++)
        	a[j] = 0 ;
        for(int j=0;j<length2;j++)
        {
        	a[m-1] = s2[n-1];
        	m-- ;
        	n-- ;
        }

        for(int j=0;j<length1;j++)
        	cout << a[j] ;

	/*	int b[length1] ;
		if(string(s1)<string(s2))
		{
			for(int j=length2-1;j>=0;j--)
			{
				if(s1[j]>s2[j])
				{
					a[j] = s1[j]-s2[j] ;
					cout << a[j] ;
				}
				else
				{
					s1[j] = s1[j] + 10 ;
					s1[j-1] = s2[j] - 1 ;
					a[j] = s1[j] - s2[j] ;
					cout << a[j] ;
				}
			}
			for(int q = 0;q<(length1-length2);q++)
			{
				a[q] = s1[q] ;
			}
		//	for(int q =0;q<length1;q++)
		//		cout << a[q] ;
		}*/
		i-- ;
	}
	return 0 ;
}