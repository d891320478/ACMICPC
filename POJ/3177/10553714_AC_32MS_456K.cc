#include <cstdio>
#include <cstring>
int n,m;
int head[5010],next[20010],e[20010];
int dfn[5010],low[5010],step;
int into[5010],color;
int vis[5010];
void dfs(int u,int p)
{
	int i;
	bool flag=0;//有重边时
	dfn[u]=low[u]=++step;
	vis[u]=1;
	for(i=head[u];i!=-1;i=next[i])
	{
		int v=e[i];
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
	for(int i=head[u];i!=-1;i=next[i])
	{
		int v=e[i];
		if(vis[v]!=0)continue;
		if(low[v]==dfn[v]) vis[v]=++color;
		else vis[v]=vis[u];
		dfs1(v);
	}
}
int main()
{
	int i,j;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++) head[i]=-1;
		for(i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			next[i*2-1]=head[u];
			e[i*2-1]=v;
			head[u]=i*2-1;
			next[i*2]=head[v];
			e[i*2]=u;
			head[v]=i*2;
		}
		step=0;
		memset(into,0,sizeof(into));
		memset(vis,0,sizeof(vis));
		dfs(1,0);
		memset(vis,0,sizeof(vis));
		vis[1]=color=1;
		dfs1(1);
		for(i=1;i<=n;i++)
		{
			for(j=head[i];j!=-1;j=next[j])
				if(vis[i]!=vis[e[j]])into[vis[i]]++;
		}
		int ans=0;
		for(i=1;i<=color;i++)
			if(into[i]==1)ans++;
		printf("%d\n",(ans+1)/2);
	}
	
	return 0;
}