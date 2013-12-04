#include <cstdio>
int n,x,ans,k,i,j,sum;
int main ()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&x);
		sum+=(x==3);
		}
		if(sum>ans)ans=sum,k=i;
	}
	printf("%d\n",k);
	
	return 0;
}