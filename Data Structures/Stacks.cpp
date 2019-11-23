#include<stdio.h>
#define MAX 100

typedef struct stack{
	int data [MAX];
	int tos;
}stack;


void display(stack *t){
	int i=t->tos-1;
	printf("\nStack Obtained: ");
	while(i>=0){
		printf("%d ",t->data[i--]);
	}
	printf("\n");
}
void push(stack *t,int ele,int n){
	t->tos<=n-1?t->data[t->tos++]=ele:printf("Stack-overflow");
	display(t);
}

void pop(stack *t){
	//printf("%d",t->tos);
	t->tos>=0?printf("Popped element : %d",t->data[--t->tos]):printf("Stack-underflow");
}

void peek(stack *t){
	t->tos>=0?	printf("Peeked element : %d",t->data[t->tos-1]):printf("Stack-empty");
}


int main(){
	stack x;
	x.tos=0;
	
	int n; printf("Enter max size of Stack : "); scanf("%d",&n);
	
	while(1){
		int choice;
		printf("\nCHOICES : 1)PUSH 2)POP 3)PEEP 4)DISPLAY 5)Exit\n");
		scanf("%d",&choice);
		if(choice == 5 )break;
		switch(choice){
			case 1: int ele;scanf("%d",&ele);push(&x,ele,n);
					break;
			case 2: pop(&x); break;
			case 3: peek(&x);break;
			case 4: display(&x); break;
			
		}		
		
	}	
	return 0;
}
