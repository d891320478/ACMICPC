#include <cstdio>
#include <cstring>

int n,m,g[1001][1001];
int dfn[1001],low[1001],step;
int bridge,bridgeu[1001],bridgev[1001];
int into[1001];
bool vis[1001];

void dfs(int u,int p)
{
	int i;
	dfn[u]=low[u]=++step;
	vis[u]=1;
	for(i=1;i<=g[u][0];i++)
	{
		int v=g[u][i];
		if(v!=p && vis[v]==1)
			if(dfn[v]<low[u]) low[u]=dfn[v];
		if(vis[v]==0)
		{
			dfs(v,u);
			if(low[v]<low[u])low[u]=low[v];
			if(low[v]>dfn[u])
			{
				bridgeu[bridge]=u;
				bridgev[bridge++]=v;
			}
		}
	}
	vis[u]=2;
}

int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) g[i][0]=0;
		for(i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][++g[u][0]]=v;
			g[v][++g[v][0]]=u;
		}
		bridge=step=0;
		memset(into,0,sizeof(into));
		memset(vis,0,sizeof(vis));
		dfs(1,0);
		//for(i=1;i<n+1;i++)
			//printf("%d   %d\n",dfn[i],low[i]);
		for(i=1;i<=n;i++)
		for(j=1;j<=g[i][0];j++)
		{
			int v=g[i][j];
			//if(i==2)printf("%d  %d    ",low[i],low[v]);
			if(low[i]!=low[v])
			{
				into[low[i]]++;
				into[low[v]]++;
			}
		}
		//printf("\n");
		//for(i=1;i<=n;i++)
			//printf("%d  ",into[i]);
		//printf("\n");
		int ans=0;
		for(i=1;i<=n;i++)
			if(into[i]==2)ans++;
		if(ans==1)ans=0;
		printf("%d\n",(ans+1)/2);
	}
	
	return 0;
}