#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define SENTINEL (-1)
#define EDIT_COST (1)
inline
int min(int a, int b)
{
   return a < b ? a : b;
}
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}
/*int EditDistanceDP(const char *X,const char *Y,int m,int n)
{
    int cost = 0;
    int leftCell, topCell, cornerCell;
    int *T = (int *)malloc(m * n * sizeof(int));
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            *(T + i * n + j) = SENTINEL;
    for(int i = 0; i < m; i++)
        *(T + i * n) = i;
    for(int j = 0; j < n; j++)
        *(T + j) = j;
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            leftCell = *(T + i*n + j-1) ;
            leftCell += EDIT_COST; 
            topCell = *(T + (i-1)*n + j);
            topCell += EDIT_COST; 
            cornerCell = *(T + (i-1)*n + (j-1) );
            cornerCell += (X[i-1] != Y[j-1]); 
            *(T + (i)*n + (j)) = Minimum(leftCell, topCell, cornerCell);
        }
    }
    cost = *(T + m*n - 1);
    free(T);
    return cost;
}*/
    int EditDistanceRecursion( const char *X,const  char *Y, int m, int n )
{
    // Base cases
    if( m == 0 && n == 0 )
        return 0;
 
    if( m == 0 )
        return n;
 
    if( n == 0 )
        return m;
 
    // Recurse
    int left = EditDistanceRecursion(X, Y, m-1, n) + 1;
    int right = EditDistanceRecursion(X, Y, m, n-1) + 1;
    int corner = EditDistanceRecursion(X, Y, m-1, n-1) + (X[m-1] != Y[n-1]);
 
    return Minimum(left, right, corner);
}
 int main()
{
	int test,p,i ;
	scanf("%d",&test);
	string s1,s2 ;
	while(test)
	{
		//scanf("%s",s1);
		//scanf("%s",s2);
		cin >> s1 >> s2 ;
		int l1,l2;
		l1 = s1.length()+1;
		l2 = s2.length()+1;
	//	char X[l1],Y[l2] ;
	//	for(i=0;i<l1;i++)
	//		x[i] = s1[i].c_str() ;
	//	for(i=0;i<l2;i++)
	//		Y[i] = s2[i].c_str() ;
        p=EditDistanceRecursion(s1.c_str(),s2.c_str(),l1,l2) ;
    	printf("%d\n",p);
    	test-- ;
	}
    return 0 ;
}