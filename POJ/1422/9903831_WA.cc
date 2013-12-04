#include <cstdio>
#include <cstring>

int t,n,m,u[150],a[150][150];

void dfs(int s)
{
	u[s]=1;
	for(int i=1;i<=a[s][0];i++)
		if(! u[a[s][i]])dfs(a[s][i]);
}

int main ()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++)
		{
			int j,k;
			scanf("%d%d",&j,&k);
			a[j][++a[j][0]]=k;
		}
		memset(u,0,sizeof(u));
		int ans=0;
		for(int i=1;i<=n;i++)
			if(! u[i])
			{
				dfs(i);
				ans++;
			}
		printf("%d\n",ans);
	}
	
	return 0;
}