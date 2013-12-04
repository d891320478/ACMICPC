#include <cstdio>

int t,n,a[50],b[50],c[50],lb,lc;
int i,j,l;

int f(int s,int t)
{
	int i,sum=0;
	for(i=s;i<=t;i++)
		if(a[i]==0)sum++;
	return sum;
}

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		l=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=b[i]-b[i-1];j++)
				a[++l]=0;
			a[++l]=1;	
		}
		lb=lc=-1;
		for(i=0;i<=l;i++)
		{
			if(a[i]==0)c[++lc]=i;
			if(a[i]==1)
			{
				b[++lb]=f(c[lc],i);
				lc--;
			}
		}
		for(i=0;i<lb;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[i]);
	}
	
	return 0;
}
