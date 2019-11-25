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

int  binarySearch(int A[],int n ,int ele){
	int l=0,u=n-1;
	int m;
	while(l<=u){
		m=(l+u)/2;
		if(A[m]==ele)return 1;
		else if(A[m]>ele)u=m-1;
		else l=m+1;
	}
	return 0;
	
}

int main(){
	int n;printf("Enter Size of Array : ");scanf("%d",&n);
	int A[n];
	get(A,n);
	set(A,n);
	
	while(1){
		int choice;printf("\nChoices 1)Element to Search 2)Exit\n");scanf("%d",&choice);
		if(choice==2)break;
		int ele;scanf("%d",&ele);
		if(binarySearch(A,n,ele)==1) printf("Found\n");
		else printf("Not Found\n");
	}
	return 0;
}
