#include <cstdio>
#include <cstring>

int t;
long n,m,into[300],g[300][300],a,b,c[300],u[300];

int tp()
{
	long i,j,k;

	for(i=1;i<=n;i++)
	{
		j=1;
		while((u[j] || into[j]) && j<=n)j++;
		u[j]=1;
		if(j>n)return 0;
		c[i]=j;
		for(k=1;k<=n;k++)
			if(g[j][k]) into[k]--;
	}
	return 1;
}

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%ld%ld",&n,&m);
		for(long i=1;i<=n;i++)
			u[i]=into[i]=0;
		memset(g,0,sizeof(g));
		for(long i=1;i<=m;i++)
		{
			scanf("%ld%ld",&a,&b);
			g[a][b]=1;
			into[b]++;
		}
		if(tp())
		{
			for(long i=1;i<n;i++)
				printf("%ld ",c[i]);
			printf("%ld\n",c[n]);
		}
		else printf("-1\n");
	}

	return 0;
}