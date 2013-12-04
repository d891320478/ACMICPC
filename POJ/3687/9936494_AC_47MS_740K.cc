#include <cstdio>
#include <cstring>

int t;
long n,m,into[300],g[300][300],a,b,c[300];

int tp()
{
	long i,j,k;

	for(i=1;i<=n;i++)
	{
		j=n;
		while(into[j] && j>0)j--;
		if(j<=0)return 0;
		into[j]=-1;
		c[j]=n-i+1;
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
			into[i]=0;
		memset(g,0,sizeof(g));
		for(long i=1;i<=m;i++)
		{
			scanf("%ld%ld",&a,&b);
			if(! g[b][a])
			{
				g[b][a]=1;
				into[a]++;
			}
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