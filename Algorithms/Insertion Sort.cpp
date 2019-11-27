#include<stdio.h>
#include<time.h>

void get(int A[],int n){
	for(int i=0;i<n;i++)scanf("%d",&A[i]);
}


void set(int A[],int n){
	for(int i=0;i<n;i++)printf("%d\t",A[i]);
}

int getminIndex(int A[],int n,int start,int val){
	int j=-1;
	for(int i=start;i<n;i++){
		if(A[i]<val){
			val=A[i];
			j=i;
		}
	}
	return j;
}

int main(){
	int n;scanf("%d",&n);int A[n];get(A,n);
	
	time_t t;
    time(&t);
    
	printf("\nBefore execution time is : %s",ctime(&t));
	
	int C=0;
	for(int i=0;i<n-1;i++){
		int ind=getminIndex(A,n,i+1,A[i]);
		if(ind>-1){
			int t=A[ind];
			A[ind]=A[i];
			A[i]=t;
		}
		
	}
	
	
	time_t t1;
    time(&t1);
    
	printf("\nAfter execution time is : %s",ctime(&t1));
	
	printf("\nSorted List : ");
	set(A,n);
		
	return 0;
	
}
