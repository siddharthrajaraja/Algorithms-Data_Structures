#include<stdio.h>
#define MAX 100

int jno[MAX];
int p[MAX];
int dead[MAX];
int vis[MAX]={0};
int max;

void accept(int n)
{   int i;
    max=0;
    printf("\nEnter Profit Deadline\n");
    
    for(i=0;i<n;i++)
    {
    	scanf("%d%d",&p[i],&dead[i]);
    	jno[i]=i+1;
    	if(dead[i]>max)max=dead[i];
	 } 
	 
	
}

void display(int n)
{
	int i;
	printf("\nJOB_NO\tPROFIT\tDEADLINE");
	for(i=0;i<n;i++)
	    printf("\n%d\t%d\t%d",jno[i],p[i],dead[i]);
	    
	printf("\nMaximum deadline: %d\n",max);   
}

void sort(int n)
{  int i,j;
   for(i=0;i<n-1;i++)
       for(j=0;j<n-1;j++)
           if(p[j]<p[j+1])
           {
           	int t=p[j];p[j]=p[j+1];p[j+1]=t;
           	t=jno[j];jno[j]=jno[j+1];jno[j+1]=t;
           	t=dead[j];dead[j]=dead[j+1];dead[j+1]=t;
		   }
}


int  isempty()
{   int i;
    for(i=0;i<max;i++)
       if(vis[i]==0)return 1;
   	return 0;
}

void job(int n)
{    int ans[max];
     
     int profit=0;
	 int i=0;
	 int j;
	 while(1)
	 {   if(isempty()==0)break;
	     for(j=dead[i]-1;j>=0;j--)
	        if(vis[j]==0){vis[j]=1;profit+=p[i];ans[j]=jno[i]; break;}
	 	i=i+1;
	 	
	  } 
	 
	 printf("\nTotal Profit: %d",profit); 
	 printf("\nFinal Job Sequencing Array: ");
	 for(i=0;i<max;i++)
	 {
	 	printf("%d\t",ans[i]);
	 }  
   	
}

void main()
{
	int n;printf("\nEnter number of jobs: ");scanf("%d",&n);
	accept(n);sort(n);display(n);job(n);
	
}

