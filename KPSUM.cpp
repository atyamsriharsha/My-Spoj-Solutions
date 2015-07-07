#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define gc getchar_unlocked
using namespace std;

void scanint(long long int &x) 
{
    register long long int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void sum(long long int x)
{
	vector<long long int> v ;
	long long int count=0,i,n,temp,temp1;
	bool turn = temp ;
	for(i=1;i<=x;i++)
	{
      temp = i ;
      if(i<10)
      {
      	if(turn)
      	{
      		count = count + i ;
      		turn = false ;
      	}
      	else
      	{
      		count = count - i ;
      		turn = true ;
      	}
      }
      else if(i>=10)
      {
      		int temp2 =0 ;
      		int n = 0 ;
      		bool turn1 = true ;
      		while(temp!=0)
      		{
      			n++ ;
      			temp1 = temp%10 ;
      			if(turn1)
      			{
      				temp2+=temp1 ;
      				turn1 = false ;
      			}
      			else
      			{
      				temp2-=temp1 ;
      				turn1 = true ;
      			}
      			temp = temp/10 ;
      		}
      		if (n%2 != 0 && turn == true) 
      		{
				count += temp2;
				turn = false;
			} 
			else if (n%2 != 0 && turn == false)
			{
				count -= temp2;
				turn = true;
			} 
			else if (n%2 == 0 && turn == false)
			{
				count += temp2;
				turn = false;
			} 
			else
			{
				count -= temp2;
				turn = true;
			}
      }
	}
       printf("%lld\n",count);
}



int main()
{
	long long int n ;
	vector<long long int>v ;
	while(1)
	{
		scanint(n) ;
		if(n==0)
			break ;
		v.push_back(n) ;
	}
	long long int size = v.size(),i ;
	for(i=0;i<size;i++)
	{
		sum(v[i]) ;
	}
	return 0 ;
}