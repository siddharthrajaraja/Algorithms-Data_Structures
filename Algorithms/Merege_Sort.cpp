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
}

void merge(int A[],int l,int m,int u,int n){
	int tem[MAX];
	int k=0;
	int i=l;
	int j=m+1;
	
	while(i<=m && j<=u){
		if(A[i]<A[j])tem[k++]=A[i++];
		else tem[k++]=A[j++];
	}
	
	while(i<=m){
		tem[k++]=A[i++];
	}
	
	while(j<=u){
		tem[k++]=A[j++];
	}
	k=0;
	
	for(i=l;i<=u	;i++){
		A[i]=tem[k++];
	}

	set(n);

}

void merge_sort(int A[],int l,int b,int n){
	int m;
	if(l<b){
		m=(l+b)/2;
		merge_sort(A,l,m,n);
		merge_sort(A,m+1,b,n);
		merge(A,l,m,b,n);	
	}
}

int main(){
	int n;scanf("%d",&n);get(n);
	set(n);
	merge_sort(A,0,n-1,n);
	set(n);
	return 0;
}
