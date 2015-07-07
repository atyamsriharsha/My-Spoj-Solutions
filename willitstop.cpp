#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std ;
int main()
{
	long long int t ;
	cin >> t ;
	if((t&(t-1))==0)
		cout << "TAK"  ;
	else
		cout << "NIE"  ;
	return 0 ;
}