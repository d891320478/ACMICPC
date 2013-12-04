#include <cstdio>
int n,m,l;
int a[200];
int main()
{
	while (scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0)break;
		l=m>n-m?m:n-m;
		a[1]=a[0]=1;
		for(int i=n-l+1;i<=n;i++)
		{
			for(int j=1;j<=a[0];j++)
			{
				a[j]*=i;
				if(j-1>0)
				{
					a[j]+=a[j-1]/10;
					a[j-1]%=10;
				}
			}
			while(a[a[0]]>=10)
			{
				a[a[0]+1]=a[a[0]]/10;
				a[a[0]]%=10;
				a[0]++;
			}
			int tmp=0,k=i-(n-l);
			for(int j=a[0];j>=1;j--)
			{
				tmp=tmp*10+a[j];
				a[j]=tmp/k;
				tmp%=k;
			}
			while(a[a[0]]==0 && a[0]>1)a[0]--;
		}
		printf("%d things taken %d at a time is ",n,m);
		for(int i=a[0];i>0;i--)
			printf("%d",a[i]);
		printf(" exactly.\n");
	}
	
	return 0;
}
