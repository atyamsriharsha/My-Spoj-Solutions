#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std ;
#define MAX 50009
#define PB push_back
#define MP make_pair
int rank[20][MAX];
typedef struct tuple
{
    int pos;
    int firstHalf,secondHalf;
}tuple;

bool compare(const tuple &a , const tuple &b)
{
    return a.firstHalf == b.firstHalf ?a.secondHalf < b.secondHalf :a.firstHalf < b.firstHalf;
}

int * suffix_array(tuple t[] ,char s[], int length)
{
    int pos = 0;
    int *arr = (int*)calloc(length+9,sizeof(int));
    for(int i=0;i<length;i++)
    {
        rank[0][i] = s[i] - 'a';
    }
    for(int cnt = 1,stp = 1;(cnt>>1) < length ; cnt<<=1,stp++)
    {
        for(int i = 0;i<length ; i++)
        {
            t[i].firstHalf = rank[stp-1][i];
            t[i].secondHalf = i+cnt < length ? rank[stp-1][i+cnt] : INT_MAX; // here i have changed the standerd suffix array
            t[i].pos = i;                                                    // it should be -1 instead of INT_MAX
        }
        sort(t,t+length,compare);
        int rnk = 0;
        for(int i = 0 ; i<length ; i++)
        {
            if((i > 0) && (t[i-1].firstHalf == t[i].firstHalf && t[i].secondHalf == t[i-1].secondHalf))
                rnk = rank[stp][t[i-1].pos];
            else
                rnk = i;
            rank[stp][t[i].pos] = rnk;
        }
    }
    pos = ceil(log(length)/log(2));
    for(int i=0;i<length;i++)
        arr[rank[pos][i]] = i;
    return arr;
}

int main()
{
	long long test ;
	int length ;
	cin >> test ;
	while(test--)
	{
		char *s ;
		s = (char *)calloc(10009,sizeof(char)) ;
		scanf("%s",s) ;
		char *str ;
		str = (char *)calloc(50000,sizeof(char)) ;
		strcat(str,s) ;
		strcat(str,s) ;
		length = strlen(s) ;
		tuple t[2*length +9] ;
		int *p ;
		p = suffix_array(t,str,2*length) ;
		printf("%d\n",p[0]+1 );

	}

	return 0 ;
}