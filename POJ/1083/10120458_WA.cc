#include <cstdio>
#include <iostream>
using namespace std;

int t,n,m,a[201],b[201],i,ans,j,k,c[201],d[201],l;

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			if(a[i]>b[i])swap(a[i],b[i]);
		}
		m=n;
		ans=0; i=0;
		while(m)
		{
			ans++;
			while(a[i]==0 && b[i]==0 && i<=n)i++;
			if(i>n)break;
			l=0;
			c[++l]=a[i]; d[l]=b[i];
			a[i]=0; b[i]=0;
			m--;
			for(j=i+1;j<=n;j++)
			if(a[j] && b[j])
			{
				int flag=1;
				for(k=1;k<=l;k++)
					if(a[j]>c[k] && a[j]<d[k] || b[j]>c[k] && b[j]<c[k])
					{
						flag=0;
						break;
					}
				if(flag)
				{
					l++;
					c[l]=a[j]; d[l]=b[j];
					a[j]=b[j]=0;
					m--;
				}
			}
		}
		printf("%d\n",ans*10);
	}
	
	return 0;
}