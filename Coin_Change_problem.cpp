#include<stdio.h>

void displaytab(long tab[][251],int r,int c)
{	printf("\nTABLE IS :\n");
	 
    int i,j;
	for(i=0;i<r;i++)
	  {
	  	for(j=0;j<c;j++)
			printf("%d ",tab[i][j]);
		printf("\n");
	  }	
}

void fill(long tab[][251],int Rs,long coin[],int r)
{    int i,j;
     for(i=0;i<=r;i++)
     {
     	for(j=0;j<=Rs;j++)
     		if(j==0)tab[i][j]=1;
     		else tab[i][j]=0;
	 }
	 
	 for(i=1;i<=r;i++)
	 {
	 	for(j=0;j<=Rs;j++)
	 	{	
	 	    if(coin[i-1]>j)tab[i][j]=tab[i-1][j];
			else tab[i][j]=tab[i-1][j]+tab[i][j-coin[i-1]]; 	
		}
	 }
	 //displaytab(tab,r+1,Rs+1);
	 printf("%ld\n",tab[r][Rs]);
	
}


void accept(long A[],int n)
{   int i;
	for(i=0;i<n;i++)scanf("%ld",&A[i]);
	
}

void display(int A[],int n)
{   printf("\nDENOMINATIONS:\n");
	int i;
	for(i=0;i<n;i++)printf("%d\t",A[i]);
}

int main()
{
	int Rs,n;scanf("%d%d",&Rs,&n);
	long A[n];accept(A,n);//display(A,n);
	long tab[251][251];	
	fill(tab,Rs,A,n);
	return 0;
}
