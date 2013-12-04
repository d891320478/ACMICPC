#include <cstdio>
#include <cstring>
int n,m,g[5002][5002];
int dfn[5002],low[5002],step;
int into[5002],color;
int vis[5002];
void dfs(int u,int p)
{
	int i;
	bool flag=0;//有重边时
	dfn[u]=low[u]=++step;
	vis[u]=1;
	for(i=1;i<=g[u][0];i++)
	{
		int v=g[u][i];
		if((v!=p || flag) && vis[v]==1)
			if(dfn[v]<low[u]) low[u]=dfn[v];
		if(vis[v]==0)
		{
			dfs(v,u);
			if(low[v]<low[u])low[u]=low[v];
		}
		if(v==p)flag=1;
	}
	vis[u]=2;
}
void dfs1(int u)
{
	vis[u]=color;
	for(int i=1;i<=g[u][0];i++)
	{
		int v=g[u][i];
		if(vis[v]!=0)continue;
		if(low[v]>dfn[u]) vis[v]=++color;
		else vis[v]=vis[u];
		dfs1(v);
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
			g[u][++g[u][0]]=v,	g[v][++g[v][0]]=u;
		}
		step=0;
		memset(into,0,sizeof(into));
		memset(vis,0,sizeof(vis));
		dfs(1,0);
		color=1;
		memset(vis,0,sizeof(vis));
		dfs1(1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=g[i][0];j++)
				if(vis[i]!=vis[g[i][j]])into[vis[i]]++;
		}
		int ans=0;
		for(i=1;i<=color;i++)
			if(into[i]==1)ans++;
		printf("%d\n",(ans+1)/2);
	}
	
	return 0;
}