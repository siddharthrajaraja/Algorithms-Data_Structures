#include<stdio.h>
#define MAX 100

int p[MAX];
int w[MAX];
float pbw[MAX];

void accept(int n)
{  int i;
   printf("\nENTER PROFIT\tWEIGHT\n");
   for(i=0;i<n;i++)
       {
       	scanf("%d%d",&p[i],&w[i]);
        pbw[i]=(float)p[i]/w[i];
	   }
	   
	
}

void display(int n)
{
	int i;
	printf("\nPROFIT\tWEIGHT\tP/W");
	
	for(i=0;i<n;i++)
	    printf("\n%d\t%d\t%f",p[i],w[i],pbw[i]); 
}

void sort(int n)
{   int i,j;
	for(i=0;i<n;i++)
	   for(j=0;j<n-1;j++)
	   if(pbw[j]<pbw[j+1])
	   {
	   	float t=pbw[j];pbw[j]=pbw[j+1];pbw[j+1]=t;
	   	int t1=p[j+1];p[j+1]=p[j];p[j]=t1;
	   	t1=w[j];w[j]=w[j+1];w[j+1]=t1;
	   	
	   }
	   
}


void fknap(int n,int x)
{   float c=0;
    int i=0;
	while(1)
	{   if(x==0)break;
	    if(x>w[i]){c=c+p[i];x=x-w[i];}
		else if(x<w[i]){c=c+pbw[i]*(float)(x);x=0;}
		printf("\nTotal Profit: %3.5f",c);
	
		i=i+1;
	}
	
}

void main()
{
	int x;
	printf("\nEnter Maximum sack capacity: ");scanf("%d",&x);
	int n;
	printf("\nEnter number of items: ");scanf("%d",&n);
	
	accept(n); sort(n);display(n);
    fknap(n,x);
	
}


