#include <iostream>
#include <cmath>
using namespace std ;
int main()
{
	int test ;
	cin >> test ;
	while(test){
		long long int n,s ;
		cin >> n ;
		s = (-1+sqrt(1+8*(n-1)))/2 ;
		cout << s << endl ;
		test-- ;}
	return 0 ;
}