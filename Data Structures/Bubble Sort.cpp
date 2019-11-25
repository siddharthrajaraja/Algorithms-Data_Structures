// Program to implement Binary Search
 
#include<stdio.h>

void get(int A[],int n){
	printf("\nEnter Elements of Array : ");
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
}

void set(int A[],int n){
	printf("\nArray Obtained : ");
	for(int i=0;i<n;i++)printf("%d\t",A[i]);
}

void bubbleSortAscending(int A[],int n){
	int i=0;
	for(i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(A[j]>=A[j+1]){
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
}

void bubbleSortDescending(int A[],int n){
	int i;
	for(i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(A[j]<A[j+1]){
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}
}


int main(){
	int n;printf("Enter Size of Array : ");scanf("%d",&n);
	int A[n];
	get(A,n);
	set(A,n);
	
	int choice ;printf("\nChoices 1)Ascending 2)Descending");scanf("%d",&choice);
	if(choice==2)bubbleSortDescending (A,n);
	else bubbleSortAscending(A,n);
	
	set(A,n);
	return 0;
}
