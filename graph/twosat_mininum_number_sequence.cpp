//HDU 1814 2-SAT 土暴力字典序最小解
int n,m,vis[NN],ans[NN];
int head[NN],next[MM],e[MM],cnt;
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dfs(int u)
{
	if(vis[u]==1) return 1;
	if(vis[u]==2) return 0;
	vis[u]=1;
	vis[u^1]=2;
	ans[++ans[0]]=u;
	for(int i=head[u];i!=-1;i=next[i])
		if(! dfs(e[i])) return 0;
	return 1;
}
int main()
{	
	while (scanf("%d%d",&n,&m)!=-1)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			add(u,v^1);
			add(v,u^1);
		}
		memset(vis,0,sizeof(vis));
		int flag=1;
		for(int i=0;flag && i<2*n;i+=2)
		if(! vis[i])
		{
			ans[0]=0;
			if(! dfs(i))
			{
				for(int j=1;j<=ans[0];j++) vis[ans[j]]=vis[ans[j]^1]=0;
				if(! dfs(i+1)) flag=0;
			}
		}
		if(flag){ for(int i=0;i<n*2;i++) if(vis[i]==1) printf("%d\n",i+1); }
		else puts("NIE");
	}
	return 0;
}
