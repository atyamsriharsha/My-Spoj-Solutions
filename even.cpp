#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std ;
int main()
{
	long int n ;
	cin >> n ;
	string k,i=0 ; 
	while(n)
	{
		cin >> k ;
		int length1 ;
		length1 = k.length() ;
		if(k[length1-1]%2==0)
		{
			
		}
        else
        {
        	cout << k << endl ;
        }
		n-- ;
	}
	return 0 ;
}