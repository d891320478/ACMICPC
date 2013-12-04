#include <cstdio>
#include <cstring>

char s[30],ch;
int n,m,g[1001][1001];
int dfn[1001],low[1001],step;
bool vis[1001];
int bridge,bridgeu[1001],bridgev[1001];
int into[1001];

void dfs(int u,int p)
{
	int i;
	dfn[u]=low[u]=++step; vis[u]=1;
	for(i=1;i<=g[u][0];i++)
	{
		int v=g[u][i];
		if(v!=p)
			if(! vis[v])
			{
				dfs(v,u);
				if(low[v]<low[u])low[u]=low[v];
				if(low[v]==dfn[v])
				{
					bridgeu[bridge]=u;
					bridgev[bridge++]=v;
				}
			}
			else if(dfn[v]<low[u])low[u]=dfn[v];
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) g[i][0]=0;
	for(i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d%c",&u,&v,&ch);
		g[u][++g[u][0]]=v;
		g[v][++g[v][0]]=u;
	}
	bridge=step=0;
	memset(vis,0,sizeof(vis));
	memset(into,0,sizeof(into));
	dfs(1,0);
	for(i=1;i<=n;i++)
	for(j=1;j<=g[i][0];j++)
	{
		int v=g[i][j];
		if(low[i]!=low[v])into[v]++;
	}
	int ans=0;
	for(i=1;i<=n;i++)
		if(into[i]==1)ans++;
	printf("%d\n",(ans+1)/2);
	
	return 0;
}