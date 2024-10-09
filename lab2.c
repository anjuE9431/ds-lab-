#include<stdio.h>
int main()
{
	int n,sum=0,j,i,a[10];
	printf("how many numbers:");
	scanf("%d",&n);

	for(i=0;i<=n-1;i++)
	{
	   scanf("%d",&a[i]);
	}
	for(j=0;j<=n-1;j++)
	{
	  sum=sum+a[j];
}
printf("sum=%d",sum);

return 0;
}


