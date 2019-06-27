#include<stdio.h>
#include<math.h>
int main()
{

   int t;
   scanf("%d",&t);  //8 4 2 6
   
   while(t!=0)
  {
  	unsigned long long n,a;
	scanf("%llu",&n);
	scanf("%llu",&a);

	int m=n%10;
	int I=0;
	unsigned long long v=a;
	while(1)
	{
		if(v%4==0)break;
		I++;
		v=v+1;
		
	}
	
	
	int ans[4];
	
	for(int i=0;i<=3;i++)
		ans[i]=int(pow(m,i+1))%10;
	
	switch(I)
	{
		case 0: printf("%d",ans[3]);break;
		case 1: printf("%d",ans[2]);break;
		case 2: printf("%d",ans[1]);break;
		case 3: printf("%d",ans[0]);break;
		
	}
	
	
  	t--;
  }
	
//	printf("%llu\t%llu",n,a);

	return 0;	
}
