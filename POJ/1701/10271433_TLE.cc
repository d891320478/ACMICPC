#include <cstdio>
int n,a,b,p[10001],i,j,k,minn,sum;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
		minn=10000000;
		for(i=1;i<=n;i++)
		{
			sum=0;
			for(j=1;j<i;j++)
				sum+=((i-j)*b+(i-j)*((i-j)-1)/2)*p[j];
			for(j=i+1;j<=n;j++)
				sum+=((j-i)*a+(j-i)*((j-i)-1)/2)*p[j];
			if(minn>sum)
			{
				minn=sum;
				k=i;
			}
		}
		printf("%d\n",k);
	}
	
	return 0;
}