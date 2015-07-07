#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std ;

void generatesubsets(int start,int num,int *arr,vector<int> &vect)
{
	int sum,mask,item ;
	for(mask=0;mask<(1<<num);mask++)
    {
        sum=0;
        for(item=0;item<num;item++)
            if(mask & (1<<item))
                sum+=arr[item+start];
        vect.push_back(sum);
    }
}

int main()
{
	int n,a,b,i ;
	unsigned long long ans = 0 ;
	vector <int> left,right ;
	vector <int>::iterator low,high ; 
	scanf("%d%d%d",&n,&a,&b) ;
	int arr[n] ;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]) ;
	}
	generatesubsets(0,n/2,arr,left) ;
	generatesubsets(n/2,n&1?n/2+1:n/2,arr,right) ;
	sort(right.begin(),right.end());
    for(int i=0;i<left.size();i++)
    {
        low=lower_bound(right.begin(),right.end(),a-left[i]);
        high=upper_bound(right.begin(),right.end(),b-left[i]);
        ans+=(high-right.begin())-(low-right.begin());
    }
    cout<<ans<<endl;
	return 0 ;
}