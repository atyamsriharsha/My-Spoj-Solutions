#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <new>
using namespace std ;
typedef struct queue
{
	int front =-1;
	int rear =-1;
	char a[1000] ;
}queue;
void enqueue(queue *q,char data)
{
	q->rear++ ;
	if(q->rear==0)
		q->front++ ;
	q->a[q->rear] = data ;
}
char dequeue(queue *q)
{
	char  p ;
	p = q->a[q->front] ;
	q->front++ ;
	return p ;
}

int main()
{
	int test ;
	cin >> test ;
	while(test>0)
	{
		queue *q = (queue *)malloc(sizeof(queue));
		int i,j ,v;
		char p ;
        cin >> v ;
        char adj[v][v] ;
        int visited[v] ;
        for(i=0;i<v;i++)
        {
        	for(j=0;j<v;j++)
        	{
        		cin >> adj[i][j] ;
        		cout << adj[i][j] ;
        	}
        }
        enqueue(q,adj[0][0]) ;
        while(!emptyqueue(q))
        {
        	p = dequeue(q) ;
        	for(j=0;j<v;j++)

        }

        

		test-- ;
	}
	return 0 ;
}