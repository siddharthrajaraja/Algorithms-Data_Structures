// This is a Doubly Linked List program for basic DLL operations
// Author: Siddharth Raja

#include<bits/stdc++.h>
using namespace std;
#define instructions cout<<"ENTER CHOICES :\n1)PUSH-BACK\n2)PUSH-FRONT\n3)POP-BACK\n4)POP-FRONT\n5)EMPTY\n6)PRINT-LIST\n7)PRINT-REVERSE\n";
	
typedef long long ll;

typedef struct node{
	node * next;
	node * prev;
	ll val;
}node;

typedef struct List{
	node *head;
	node *tail;

}List;

void pushb(List *,ll);
bool isEmpty(List *);
void printList(List *);
void printReverseList(List *);
void pushf(List *,ll);
void popb(List *l);
void popf(List *);

int main(){
		List x;
		x.head=NULL;
		x.tail=NULL;
		ll ele;
		while(1){
		instructions
		
		int choice;cin>>choice;
	
		switch(choice){

			case 1: cin>>ele; pushb(&x,ele);
					break;
			case 2: cin>>ele; pushf(&x,ele);
					break;
			case 3: popb(&x);break;
			case 4: popf(&x);break;
			case 5: (isEmpty(&x))?cout<<"LIST IS EMPTY\n":cout<<"LIST IS NOT EMPTY\n";
					break;
			case 6: printList(&x);
				   	break;
			case 7: printReverseList(&x);
					break;	
		}
	
	}
		
	
	return 0;
}

void pushb(List *l,ll ele){
	node * newNode =(node *)malloc(sizeof(node));
	newNode->next=NULL;
	newNode->val=ele;
	if(l->head==NULL){
			newNode->prev=NULL;
			l->head=newNode;
			l->tail=newNode;
			return ;
	}
	newNode->prev=l->tail;
	l->tail->next=newNode;
	l->tail=newNode;
}


void printList(List *l){
	if(isEmpty(l)){cout<<"LIST IS EMPTY"<<"\n";return ;}
	cout<<"LIST OBTAINED: ";
	node *p=l->head;
	while(p!=NULL){
		cout<<p->val<<" ";
	   p=p->next;	
	}
	cout<<endl;
}

void printReverseList(List *l){
	if(isEmpty(l)){cout<<"LIST IS EMPTY"<<"\n";return ;}
	cout<<"REVERSED LIST :";
	node *p=l->tail;
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->prev;
	}
	cout<<endl;
}

bool isEmpty(List *l){
	if(l->head==NULL)return true;
	return false;
}

void pushf(List *l,ll ele){
	node *newNode =(node *)malloc(sizeof(node));
	newNode->prev=NULL;
	newNode->val=ele;
	if(isEmpty(l)){
			newNode->next=NULL;
			l->head=newNode;
			l->tail=newNode;
			return ;
	}

	newNode->next=l->head;
	l->head->prev=newNode;
	l->head=newNode;
}

void popb(List *l){
	if(isEmpty(l)){
		cout<<"LIST EMPTY\n";
		return ;
	}
	if(l->head->next==NULL){
		cout<<"POPPED BACK ELEMENT: "<<l->head->val<<"\n";
		l->head=NULL;
		l->tail=NULL;
		return ;
	
	}
	
	cout<<"POPPED BACK ELEMENT :"<<l->tail->val<<"\n";
	l->tail=l->tail->prev;
	l->tail->next=NULL;
}

void popf(List *l){
	if(isEmpty(l)){
		cout<<"LIST EMPTY\n";
		return ;
	}
	if(l->head->next==NULL){
		cout<<"POPPED FRONT ELEMENT: "<<l->head->val<<"\n";
		l->head=NULL;
		l->tail=NULL;
		return ;
	}
	
	cout<<"POPPED FRONT ELEMENT: "<<l->head->val<<"\n";
	l->head=l->head->next;
	l->head->prev=NULL;



}
