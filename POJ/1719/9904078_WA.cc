#include <cstdio>
#include <cstring>

int n,m,t;
int u[150],va,a[150];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(u,0,sizeof(u));
		a[0]=0;
		for(int i=1;i<=m;i++)
		{
			int j,k;
			scanf("%d%d",&j,&k);
			if(! u[j])
			{
				u[j]=1;
				a[++a[0]]=j;
			}
			else
			if(! u[k])
			{
				u[k]=1;
				a[++a[0]]=k;
			}
		}
		if(n>m)printf("NO\n");
		else if(a[0]<n)printf("NO\n");
			else
			{
				for(int i=1;i<n;i++)
					printf("%d ",a[i]);
				printf("%d\n",a[n]);
			}
	}
	return 0;
}
