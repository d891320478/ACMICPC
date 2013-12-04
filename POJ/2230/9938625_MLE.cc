#include <cstdio>

int g[10001][10010],a[10001][10010];
long n,m;

void dfs(long s)
{
	for(long i=1;i<=a[s][0];i++)
	{
		if(g[s][a[s][i]])
		{
			g[s][a[s][i]]--;
			dfs(a[s][i]);
		}
	}
	printf("%ld\n",s);
}

int main ()
{
	scanf("%ld%ld",&n,&m);
	for(long i=1;i<=m;i++)
	{
		long b,c;
		
		scanf("%ld%ld",&b,&c);
		if(! g[b][c])
		{
			g[b][c]=g[c][b]=1;
			a[b][++a[b][0]]=c;
			a[c][++a[c][0]]=b;
		}
	}
	dfs(1);

	return 0;
}