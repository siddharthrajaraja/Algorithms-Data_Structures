#include<stdio.h>


void accept(int A[],int n)
{
	int i;for(i=0;i<n;i++)scanf("%d",&A[i]);
	
}

void display(int A[],int n)
{   int i;for(i=0;i<n;i++)printf("%d\t",A[i]);
	
}

int  partition(int A[],int l,int u)
{   int pi=A[l];
    int a=l+1;int b=u;
    
    while(a<=b)
    {
    	while (a<=b && A[a]<pi)a++;
    	while(A[b]>pi)b--;
    	
    	if(a<b){int t=A[a];A[a]=A[b];A[b]=t;}
    	
    	  
	}
	
	A[l]=A[b];
	A[b]=pi;
	return b;
    
	
}

void qs(int A[],int l,int u)
{
	int p;
	
	if(l<u)
	{
		p=partition(A,l,u);
		qs(A,l,p-1);
		qs(A,p+1,u);
	}
}

void main()
{   int n;scanf("%d",&n);int A[n];accept(A,n);
    printf("\nList: "); display(A,n);
    qs(A,0,n-1);
    
    printf("\nSorted List: "); display(A,n);
    
    
   
}
