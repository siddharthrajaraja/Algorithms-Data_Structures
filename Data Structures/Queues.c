// This program is Linear Queue implementation . 
#include<stdio.h>
#define MAX 100

typedef struct queue{
	int data[MAX];
	int front ,rear ;
}queue;

void enqueue(queue *t,int n,int ele){
	t->rear<=n?t->data[t->rear++]=ele:printf("Queue Overflow");
}

void dequeue(queue *t,int n){
	t->front==n?printf("\nQueue Underflow "):printf("Deleted Element : %d",t->data[t->front++]);
}

void display(queue *t){
	int i=t->front;
	printf("\nQueue obtained: ");
	
	while(i<t->rear){
		printf("%d\t",t->data[i++]);
	}
	printf("\n");
}


int main(){
	queue x;
	x.front=0;
	x.rear=0;
	
	
	int n; printf("Enter max size of Queue : "); scanf("%d",&n);
	
	while(1){
		int choice;
		printf("\nCHOICES : 1)ENQUEUE 2)DEQUEUE 3)PEEK 4)DISPLAY 5)Exit\n");
		scanf("%d",&choice);
		if(choice == 5 )break;
		int ele;
		switch(choice){
			case 1: scanf("%d",&ele);
					enqueue(&x,n,ele);
					break;
			case 2: dequeue(&x,n); break;
//			case 3: peek(&x);break;
			case 4: display(&x); break;
			
		}		
		
	}	
	
	
	return 0;
}
