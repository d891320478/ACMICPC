void dfs(int u,int p)
{
	int s=0,flag=0,sum=0;
	dfn[u]=low[u]=++step;	vis[u]=1;
	for(int v=1;v<=n;v++)
	if(g[u][v] && v!=p)
	{
		if(! vis[v])
		{
			dfs(v,u);		s++;
			if(low[v]<low[u])low[u]=low[v];
			if(low[v]>=dfn[u]) flag=1;
		}
		else if(dfn[v]<low[u])low[u]=dfn[v];
	}
	if((p<0 && s>1) || (p>0 && flag)) cut[u]=1;
}
int main()
{
	memset(vis,0,sizeof(vis));	step=0;
		for(int i=1;i<=n;i++)		if(! vis[i]) dfs(i,-1);
}
