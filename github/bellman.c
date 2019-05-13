#include<stdio.h>
#include<malloc.h>
#define MAX 1000000

int dis[MAX];
int pi[MAX];


typedef struct node
{
	struct node * next;
	int s;int d;int wt;
	
}node;

typedef struct  head
{
	node * start;
}head;

void display(head *t)
{
	node *p;
	p=t->start;
	while(p!=NULL)
	{   printf("\n%d\t%d\t%d",p->s,p->d,p->wt);
	
		p=p->next;
	}
	
}
void accept(head *t)
{   int src,des,w;
    scanf("%d%d%d",&src,&des,&w);
    
	node *q;
	q=(node *)malloc(sizeof(node));
	q->next=NULL;
	q->s=src;q->d=des;q->wt=w;
	
	if (t->start==NULL)
		{t->start=q;return;
		}
	node *p;
	p=t->start;
	while(p->next!=NULL)p=p->next;
	p->next=q;
		
}

void fill(int n)
{
	int i;for(i=0;i<n;i++){dis[i]=MAX;pi[i]=-1;	}
}

void displayt(int n)
{   printf("\nDISTANCE ARRAY: "); 
	int i;for(i=0;i<n;i++)printf("%d\t",dis[i]);
	printf("\nPATH ARRAY: "); for(i=0;i<n;i++)printf("%d\t",pi[i]);
	
}

void bellman(head *t,int n,int src)
{
	int i;
	dis[src-1]=0;
	for(i=0;i<n-1;i++)
	    {
	    	node *p;p=t->start;
	    	while (p!=NULL)
	    	{   if(dis[p->s-1]+p->wt<dis[p->d-1])
	    	        {
	    	        	dis[p->d-1]=dis[p->s-1]+p->wt;
	    	        	pi[p->d-1]=p->s;
	    	        	
					}
	    		p=p->next;
			}
	    	
		}
	node *p;
	p=t->start;
	while(p!=NULL)
	{
		 if(dis[p->s-1]+p->wt<dis[p->d-1])
	    	        {
	    	        	printf("\nNEGATIVE WEIGHT CYCLE FOUND\n");return;
	    	        	
					}
	    		p=p->next;
		
	}	
	
	displayt(n);
		
}


void main()
{   head x;
    x.start=NULL;
	int n,e;scanf("%d%d",&n,&e);
	
	int i;
	for(i=0;i<e;i++)accept(&x);
	int src;
	printf("\nEnter source: ");scanf("%d",&src);
	
	
	printf("\nSRC\tDES\ttWT");
	display(&x);fill(n);bellman(&x,n,src);
	
	
}
