#include<stdio.h>
#include<string.h>

void display(int tab[][100],int r,int c)
{
	int i,j;
	for(i=0;i<r;i++){for(j=0;j<c;j++)printf("%d\t",tab[i][j]);printf("\n");}
}


void displayseq(int tab[][100],char X[],char Y[],int r,int c)
{    int i=r;int j=c;
     char seq[tab[i][j]-1];
     int h=0;
	 
	 //printf("%d  %d  %d",i,j,tab[i][j]);
	 while(i>=1)
	 {   if(X[i-1]==Y[j-1])  { seq[h++]=X[i-1];i--;j--;}
	 	 else
	 	     if (tab[i-1][j]>tab[i][j-1]) i--;
	 	     else j--;
	 }  
	
	printf("\nLONGEST COMMON SUBSEQUENCE IS: ");
	for(i=h;i>=0;i--)printf("%c",seq[i]);
	
}

void fill(int tab[][100],char X[],char Y[])
{   int r=strlen(X)+1;
    int c=strlen(Y)+1;
	int i,j;
	for(i=0;i<r;i++)tab[i][0]=0;for(i=0;i<c;i++)tab[0][j]=0;
	for (i=1;i<=r;i++)
	{
		for (j=1;j<=c;j++){if(X[i-1]==Y[j-1])tab[i][j]=tab[i-1][j-1]+1;else if (tab[i-1][j]>tab[i][j-1]) tab[i][j]=tab[i-1][j];else tab[i][j]=tab[i][j-1];}
	}
	printf("\nLONGEST COMMON SUBSEQUENCE TABLE :\n ");display(tab,r,c);displayseq(tab,X,Y,r,c);	
}

void main()
{   int n,m;
    //scanf("%d%d",&n,&m);
	//printf("%d%d",n,m); 
	char X[100],Y[100];
	int tab[100][100];gets(X);gets(Y);fill(tab,X,Y);
	
}
