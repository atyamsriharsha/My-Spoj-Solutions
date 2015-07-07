#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cstdio>
using namespace std ;
int main()
{
	int test ;
	double a ;
	cin >> test ;
	while(test--)
	{
         cin >> a ;
         printf("%0.6lf\n", 1 - 1/(3*sqrt(a/2)));
	}
	return 0 ;
}