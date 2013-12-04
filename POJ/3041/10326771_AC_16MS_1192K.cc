#include <cstdio>
#include <cstring>
int n,m;			int g[510][510],vis[510],h[510],q[510],va;
int dfs(int i)
{
    for(int j=1;j<=g[i][0];j++)
  	if(! vis[g[i][j]])
  	{
   		vis[g[i][j]]=1;
   		if( (q[g[i][j]]==0) || (dfs(q[g[i][j]])) )
   		{	q[g[i][j]]=i;	h[i]=g[i][j];	return 1;		}
  	}
    return 0;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		va=0;
		memset(vis,0,sizeof(vis));	memset(h,0,sizeof(h));	memset(q,0,sizeof(q));
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u][++g[u][0]]=v;
			if(! vis[v])	if(! h[u])
			{	    va++;	    h[u]=v;	    q[v]=u;	    vis[v]=1;		}
		}
		for(int i=1;i<=n;i++)
		if(! h[i])
		{	memset(vis,0,sizeof(vis));	if(dfs(i))va++;	}
		printf("%d\n",va);
	}
	return 0;
}
