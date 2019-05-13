#include<stdio.h>
void accept(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	   scanf("%d",&A[i]);  
}

void display(int A[],int n)
{
	printf("\n"); 
	int i;
	for(i=0;i<n;i++)printf("%d ",A[i]);
}

void insert(int A[],int n)
{   int i,j;
   for(i=0;i<n-1;i++)
   {   int val=A[i];
	   	for(j=i+1;j>0;j--)
	   	{   if (A[j]<A[j-1])
	   	    {
	   	       int t=A[j];
			   A[j]=A[j-1];
			   A[j-1]=t;
			 }
	   	
		
		   }
		   
       		   display(A,n);	  	
		
   }
	
}

void main()
{
	int n;scanf("%d",&n);
	int A[n];int ch;
	accept(A,n);int ele;
	//oprintf("\nList: ");display(A,n);
	insert(A,n);
}
