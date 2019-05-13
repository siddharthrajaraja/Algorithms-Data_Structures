#include<stdio.h>
#include<string.h>
#define MAX 1000

typedef struct stack
{ char s[MAX];
  int tos;
	
}stack;

int chko(char v)
{
	if(v=='{' || v=='[' || v=='(') return 1;
	 return 0;
}

int chkc(char v)
{
		if(v==']' || v=='}' || v==')') return 1;
	 return 0;
	
}

void push(stack *t,char ele)
{  t->tos++;
   t->s[t->tos]=ele;
	
}

int isEmpty(stack *t)
{
	if(t->tos==-1) return 1;
	return 0;
}

char pop(stack *t)
{
	if(isEmpty(t)) return '-';
	t->tos--;
	return t->s[t->tos+1];
}

void main()
{
	stack x;
	x.tos=-1;
	char A[1000];
	gets(A);
	int l=strlen(A);
	int i;
	for(i=0;i<l;i++)
	{
		char v=A[i];
		if(chko(v)) push(&x,v);
		if(chkc(v)){
			           if(isEmpty(&x)) {  printf("\nNO");return;
					                  }
					   else
					      {  char z=pop(&x);
					      	  if(v=='(' && z!=')') {printf("\nNO");return;}
								
					      	  if(v=='[' && z!=']') {printf("\nNO");return;}
					      	  if(v=='{' && z!='}') {printf("\nNO");return;}
					      	  
						  }              
		           }
		
	}
	
	if(isEmpty(&x)) printf("\nYES");
	else  printf("\nNO");
	
}
