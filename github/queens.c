#include<stdio.h>
#include<math.h>
int x[10];

void display(int n)
{   //printf("\n");
	int i;
	for(i=1;i<=n;i++)
	   printf("%d ",x[i]);
	   
	
}
int  nextval(int k,int i,int n)
{   int j;
	for(j=1;j<=k-1;j++)
	{
		
		if ((i==x[j]) || abs(i-x[j])==abs(k-j))
		   {
		  // 	display(n);
		  
		   	return 0;
		  
		   }
		   
		    
	}
	
	return 1;
}

void nqueens(int k,int n)
{
	
	int i;
	for(i=1;i<=n;i++)
	{
		if(nextval(k,i,n)==1)
		  {
		  	x[k]=i;
		  	if(k==n)
		  	
				 {printf("\nValid soltn: "); display(n);
				 }		  	  
		  	else
		  	{   printf("\nInvalid soltn: ");display(n);
		  		nqueens(k+1,n);
				
			  }
			       
		  }
	}
	
	
}

void main()
{
	int n;
	printf("Enter no. of queen: ");
	scanf("%d",&n);
	
	
	nqueens(1,n);
	//display(x,n);
	
	
}
