#include <cstdio>
#include <cstring>
int n,m;
int head[5001],next[20001],e[20001];
int dfn[5001],low[5001],step,color,vis[5001];
int b[20001][2],bridge=-1,into[5001];
void dfs(int u,int p)
{
	int i; bool flag=0;
	dfn[u]=low[u]=++step;
	vis[u]=1;
	for(i=head[u];i!=-1;i=next[i])
	{
		int v=e[i];
		if(vis[v]==1 && (v!=p || flag))
			if(dfn[v]<low[u])low[u]=dfn[v];
		if(vis[v]==0)
		{
			dfs(v,u);
			if(low[v]<low[u])low[u]=low[v];
			if(low[v]==dfn[v])
			{
				bridge++;
				b[bridge][0]=u;
				b[bridge][1]=v;
			}
		}
		//if(v==p)flag=1;
	}
	vis[u]=2;
}
void dfs1(int u)
{
	vis[u]=color;
	for(int i=head[u];i!=-1;i=next[i])
	{
		int v=e[i];
		if(low[v]<=dfn[u])
			if(! vis[v]) dfs1(v);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		next[i*2]=head[u]; head[u]=i*2; e[i*2]=v;
		next[i*2+1]=head[v]; head[v]=i*2+1; e[i*2+1]=u;
	}
	for(int i=1;i<=n;i++)
		if(! vis[i]) dfs(i,0);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(! vis[i])
		{
			color++;
			dfs1(i);
		}
	for(int i=0;i<=bridge;i++)
	{
		into[vis[b[i][0]]]++;
		into[vis[b[i][1]]]++;
	}
	int ans=0;
	for(int i=1;i<=color;i++)
		if(into[i]==1)ans++;
	if(ans==1)printf("0\n");
	else printf("%d\n",(ans+1)/2);
	
	return 0;
}