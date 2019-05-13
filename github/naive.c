#include<stdio.h>
#include<string.h>

void naive (char T[],char P[])
{   int x=strlen(T);int y=strlen(P);
    int i,j=0;
	int m=0;
	int ans=0;
	for(i=0;i<abs(x-y);i++)
	{   m=0;
	    if (T[i]==P[0])
		{  //printf("\nYEs"); 
		   for(j =1;j<y;j++)
		   {   
		   	   if(T[j+i]!=P[j]){m=1; break;}
			}	
			if(m==0 && j==y)
			    {
				  ans=1;
			    printf("\nPattern matched at %d",i);
			}
			    
		}	
	}	
	
	if(ans==0)
	printf("\nPattern not matched");
	
}
void main()
{
	char T[100],P[100];
	printf("\nEnter Text: ");gets(T);
	printf("\nEnter Pattern: ");gets(P);
	naive(T,P);
	
}
