#include<stdio.h>
#include<malloc.h>
typedef struct list{
	list *next;
	int data;
	
}list;

typedef struct head{
	list *start;
}head;


void printList(head *t){
	list *p;
	p=t->start;
	if(p==NULL){  printf("\nLIST EMPTY \n");return ;
	}
	printf("\nList Obtained : ");
	
	while(p!=NULL){
		printf("%d\t",p->data);
		p=p->next;
		}
}

void insertBegin(head *t,int ele){
	list *p =(list *)malloc(sizeof(list));
	p->data=ele;
	if(t->start==NULL){
		t->start=p;
		p->next=NULL;	
		return;
	}
	p->next=t->start;
	t->start=p;
}

void insertEnd(head *t,int ele){
	list *p =(list *)malloc(sizeof(list));
	p->next=NULL;
	p->data=ele;
	list *q;
	q=t->start;
	if(q==NULL){
		     t->start=p;
		     return ;
	}
	while(q->next=NULL)q=q->next;
	q->next=p;
}

int getCount(head *t){
	list *q;q=t->start;
	int c=0;
	while(q!=NULL){ q=q->next;c++;
	}
	return c;	
}

// Under Developemnt

void insertBetween(head *t,int ele,int pos){
	list *p=(list *)malloc(sizeof(list));
	p->data=ele;
	int c=0;
	
	
}


int main(){
	head x;
	x.start=NULL;
	
	while(1){
		int ch;
		printf("\nChoices : 0)EXIT 1)Insert 2)Delete 3)Reverse 4)DISPLAY 5)Count Nodes ----> \n"); scanf("%d",&ch);
		
		if(ch==0)break;
		
		switch(ch){
			case 1: 
			        int innerChoices;
					printf("\nLocation : 0)Exit 1)BEGINING 2)END 3)IN BETWEEN ---- > \n");
					 scanf("%d",&innerChoices);
					if(innerChoices ==0)break;
					int ele; printf("\nEnter Element to insert :  "); scanf("%d",&ele);
					
					switch(innerChoices){
							case 1: insertBegin(&x,ele);
									printList(&x); 
									break;
							
							case 2: insertEnd(&x,ele);	
									printList(&x);
									break;
							case 3: int pos;
									printf("\nEnter position to insert element : \n");scanf("%d",&pos);
									if(pos>=1 && pos<=getCount(&x)){
										if(pos==1){
											insertBegin(&x,ele);
											printList(&x);
										}
										else if(pos==getCount(&x)){
											insertEnd(&x,ele);
											printList(&x);
											
										}
										else{
											
										}
									}
									else{
										printf("\nInvalid Position Encountered\n");
									}
									
									break;
							default: printf("\nEnter valid Inner Choices !!\n");
											
						
					}
					 
					break;
			case 4: printList(&x);
					break;
			
			case 5: printf("Number of nodes in Linked List : %d\n",getCount(&x));
					break;
			default: printf("\nEnter valid Choices !!\n");		
		}
	}		
	
	
	return 0;
	
}
