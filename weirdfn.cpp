#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstdio>
#include <vector>
#include <functional>
using namespace std ;
int main()
{
	int test,a,b,c,n,i,m ;
	cin >> test ;
    unsigned long long sum = 0,r ;
	while(test--)
	{
		cin >> a >> b >> c >> n ;
		sum = 1ULL;
	 	priority_queue <int,vector<int>,less <int> > Left ;
	 	priority_queue <int,vector<int>,greater <int> > Right;
	 	Left.push(1);
 		int ls=Left.size(),rs = Right.size();
	 	for(i=2;i<=n;i++)
	 	{
	 	    m = Left.top();
	 	    r = (1ULL*a*m + 1ULL*b*i + c)%1000000007;
	 		sum+=r;
	 		if(m>r)
	 		{
	 			Left.push(r);
	 			ls++;
	 		}
	 		else
	 		{
	 			Right.push(r); 
	 			rs++;
	 		}
	 		while(ls>rs+1)
	 		{
	 			Right.push(Left.top()); 
	 			Left.pop();
	 			ls--; 
	 			rs++;
	 		}
	 		while(rs>ls)
	 		{
	 			Left.push(Right.top()); 
	 			Right.pop();
	 			rs--;
	 			ls++;
	 		}
	 	}
	 	cout << sum << endl ;
	}
	return 0 ;
}