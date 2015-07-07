#include <iostream>
#include <cmath>
#include <limits.h>
#include <stdio.h>
#include <string>
using namespace std ;
int main()
{
	int test ;
	cin >> test ;
	while(test)
	{
		int n,m ;
		cin >> n >> m ;
		string content ;
		cin >> content ;
		int a[m][m] ;
		while(m)
		{
			cin >> i >> j >> w ;
			a[i][j] = w ;
			m-- ;
		}

		test-- ;
	}
	return 0 ;
} 