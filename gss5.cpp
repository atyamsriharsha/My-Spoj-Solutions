#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>
#include <utility>
#include <cstring>
#include <string>
#include <queue>
#include <numeric>
#include <cassert>
#include <set>
using namespace std ;
#define INF int(1e9)
#define X first
#define Y second
//#define int long long int
#define MAXN 110000
#define REP(i,n) for(int i=0;i<n;i++)
int N,Q ;
int sum[2*MAXN], leftmax[2*MAXN], rightmax[2*MAXN], midmax[2*MAXN], best[2*MAXN], A[MAXN], cumsum[MAXN];

struct node
{
	int left,sum,right,mid,curmax,res,mres ;
	node(int a=0,int b=-INF,int c=-INF,int d=-INF,int e=-INF):
	sum(a),left(b),right(c),mid(d),curmax(e)
	{
		res= max(max(sum,left),max(mid,right)) ;
		res = max(res,curmax) ;
	}
};
void  build(int from,int to,int index)
{
	if(from>to)
	{
         return ;
	}
	if(from==to)
	{
		sum[index] = leftmax[index] = rightmax[index] = midmax[index] = best[index] = A[from] ;
		return ; 
	}
	int lt=2*index,rt = 2*index +1,mid = (from+to)/2 ;
	build(from,mid,lt) ;
	build(mid+1,to,rt) ;
	sum[index] = sum[lt] + sum[rt] ;
	leftmax[index] = max(sum[lt] + leftmax[rt],leftmax[lt]);
	rightmax[index] = max(rightmax[rt], sum[rt] + rightmax[lt]);
	midmax[index] = max(max(leftmax[rt] + rightmax[lt], rightmax[lt]), leftmax[rt]);
	int cands[] = {sum[index], leftmax[index], rightmax[index], midmax[index], best[lt], best[rt]};
	best[index] = *max_element(cands, cands+6);
}
node query(int a, int b, int x, int i, int j) 
{
	if(a>b || a>j || b<i) 
	{
		node n;
		n.res = -INF;
		return n;
	} 
	if(a >= i && b <= j) 
	{
		return node(sum[x], leftmax[x], rightmax[x], midmax[x], best[x]);
	}
	int lt = 2*x, rt = 2*x+1, mid = (a + b) / 2;
	node nleft = query(a, mid, lt, i, j);
	node nright = query(mid+1, b, rt, i, j);
	return node (
			nleft.sum + nright.sum, 
			max(nleft.left, nleft.sum + nright.left), 
			max(nright.right, nright.sum + nleft.right),
			max(max(nleft.right, nleft.right + nright.left), nright.left),
			max(nleft.res, nright.res)
		);
}

int rsq(int a,int b)
{
	if(a>b)
		return 0 ;
	return cumsum[b] - cumsum[a-1] ;
}

int solve(int x1,int y1,int x2,int y2)
{
	if(y1<x2)
	{
		int lquery = query(1,N,1,x1,y1).right ;
		int middle = rsq(y1+1,x2-1) ;
		int rquery = query(1,N,1,x2,y2).left ;
		return lquery+middle+rquery ;
	}
	else
	{
		int left1 = query(1, N, 1, x1, x2).right;
		int right1 = query(1, N, 1, x2+1, y2).left;
		int piv1 = max(left1, left1+right1);
		int left2 = query(1, N, 1, x1, y1).right;
		int right2 = query(1, N, 1, y1+1, y2).left;
		int piv2 = max(left2, left2+right2);
		int piv3 = query(1, N, 1, x2, y1).res;
		return max(max(piv1, piv2), piv3);
	}
}

int main()
{
	int test ;
	int n,i ;
	scanf("%d",&test) ;
	while(test)
	{
		scanf("%d",&n);
		//inta[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&A[i+1]);
		}
		memset(cumsum,0,sizeof(cumsum)) ;
		for(i=1;i<=N;i++)
			cumsum[i] = cumsum[i-1] + A[i] ;
		build(1,n,1);
		scanf("%d",&Q);
		REP(i,Q)
		{
			int x1,y1,x2,y2 ;
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2) ;
			printf("%d\n",solve(x1,y1,x2,y2));
		}
		test-- ;
	}
	return 0 ;
}