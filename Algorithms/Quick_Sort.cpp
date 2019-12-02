#include<stdio.h>
#define MAX 10000

int A[MAX];

void get(int n){
	int i;
	for(i=0;i<n;i++)scanf("%d",&A[i]);	
	
}

void set(int n){
	int i;
	printf("\nList Obtained: ");
	for(i=0;i<n;i++)printf("%d\t",A[i]);	
	printf("\n");
}

int partition(int A[],int l,int u){
	int pi=A[l];
	int low=l+1;
	int up=u;
	while(low<=up){
		while(A[low]<=pi)low++;
		while(A[up]>pi) up--;
		if(low<=up){
			int t=A[low];
			A[low]=A[up];
			A[up]=t;
		}
		
	}
	
	
	A[l]=A[up];
	A[up]=pi;
	
	return up;
		
	
}


void quickSort(int A[],int l,int u){
	if(l<u){
		int p=partition(A,l,u);
		quickSort(A,l,p-1);
		quickSort(A,p+1,u);
		
	}
}


int main(){
	int n;scanf("%d",&n);get(n);
	set(n);
	quickSort(A,0,n-1);
	printf("\n");
	set(n);
	
	return 0;
}
