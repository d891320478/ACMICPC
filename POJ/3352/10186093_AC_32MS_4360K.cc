#include <cstdio>
#include <cstring>

int n,m,g[1001][1001];
int dfn[1001],low[1001],step;
int bridge,bridgeu[1001],bridgev[1001];
int into[1001],color;
int vis[1001];
bool bri[1001][1001];

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
void dfs1(int u)
{
	vis[u]=color;
	for(int i=1;i<=g[u][0];i++)
	{
		int v=g[u][i];
		if(low[v]<dfn[u])
			if(! vis[v]) dfs1(v);
	}
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
		color=0;
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
			if(! vis[i])
			{
				color++;
				dfs1(i);
			}
		for(i=0;i<bridge;i++)
		{
			into[vis[bridgeu[i]]]++;
			into[vis[bridgev[i]]]++;
		}
		int ans=0;
		for(i=1;i<=color;i++)
			if(into[i]==1)ans++;
		if(ans==1)ans=0;
		printf("%d\n",(ans+1)/2);
	}
	
	return 0;
}