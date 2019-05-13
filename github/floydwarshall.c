#include<stdio.h>
#define MAX 100

//int A[MAX][MAX];
//int path[MAX][MAX];

void fill(int n,int path[][MAX],int A[][MAX])
{
	int i,j;
	for(i=0;i<n;i++){
						for(j=0;j<n;j++)
							if(i==j)A[i][j]=0;else A[i][j]=10000;	
							path[i][j]=-1;
						}
	
}

void displaytab(int n,int path[][MAX],int A[][MAX])
{
	int i,j;
	printf("\nDISTANCE MATRIX:\n");
	for(i=0;i<n;i++){for(j=0;j<n;j++)printf("%d\t",A[i][j]);printf("\n");}
	printf("\nPATH MATRIX:\n");
	for(i=0;i<n;i++){for(j=0;j<n;j++)printf("%d\t",path[i][j]);printf("\n");}
	
	    
}


void accept(int e,int n,int path[][MAX],int A[][MAX])
{
	int i,j;
	int src,wt,des;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&src,&des,&wt);
		A[src-1][des-1]=wt;
		path[src-1][des-1]=src;
		
	}
	
	//displaytab(n,path,A);
}

void floyd(int path[][MAX],int A[][MAX],int n)
{
	int i,j,k;
	//printf("YEs");
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				   {
				   	A[i][j]=A[i][k]+A[k][j];
				   	path[i][j]=k+1;
					}
					 
				    
				
			}
		}
		displaytab(n,path,A);
	}
	
	displaytab(n,path,A);
}

void main()
{
	int A[MAX][MAX];
	int path[MAX][MAX];
	
	int n;int e;
	scanf("%d%d",&n,&e);
	fill(n,path,A);
//	displaytab(n,path,A);
	accept(e,n,path,A);
	floyd(path,A,n);
}

