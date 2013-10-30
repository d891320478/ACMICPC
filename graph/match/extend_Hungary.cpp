bool dfs(int u)
{
	for(int v=1;v<=m;++v)
	if(g[u][v] && ! vis[v])
	{
		vis[v]=1;
		if(match[v][0]<sum[v])
		{
			match[v][++match[v][0]]=u;
			return 1;
		}
		for(int i=1;i<=match[v][0];++i)
			if(dfs(match[v][i]))
			{
				match[v][i]=u;
				return 1;
			}
	}
	return 0;
}
