void dfs(int u,int p)
{
	int i;
	bool flag=0;//有重边时
	dfn[u]=low[u]=++step;	vis[u]=1;
	for(i=head[u];i!=-1;i=next[i])
	{
		int v=e[i];
		if((v!=p || flag) && vis[v]==1)		if(dfn[v]<low[u]) low[u]=dfn[v];
		if(vis[v]==0)
		{		dfs(v,u);		if(low[v]<low[u])low[u]=low[v];		}
		if(v==p)flag=1;
	}
	vis[u]=2;
}
