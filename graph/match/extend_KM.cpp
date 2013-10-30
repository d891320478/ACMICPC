//SPOJ ASSIGN4
int match[N][N];
int nw[N],lst[N],sx[N],sy[N],lx[N],ly[N];
int slack[N],g[N][N],ans;
int nx,ny;
int a[N],b[N];
bool dfs(int u)
{
	if(sx[u]) return 0;
	sx[u]=1;
	for(int v=1;v<=ny;++v)
	if(! sy[v])
	{
		int tmp=lx[u]+ly[v]-g[u][v];
		if(! tmp)
		{
			sy[v]=1;
			if(b[v])
			{
				nw[u]=v;
				lst[u]=0;
				return 1;
			}
			for(int i=1;i<=nx;++i)
			if(match[i][v] && dfs(i))
			{
				nw[u]=v;
				lst[u]=i;
				return 1;
			}
		}
		else slack[v]=min(slack[v],tmp);
	}
	return 0;
}
int push(int u)
{
	int d=a[u];
	for(int i=u;i;i=lst[i])
		if(lst[i]) d=min(d,match[lst[i]][nw[i]]);
		else d=min(d,b[nw[i]]);
	int sum=0;
	a[u]-=d;
	for(int i=u;i;i=lst[i])
	{
		if(lst[i]) sum-=d*g[lst[i]][nw[i]],match[lst[i]][nw[i]]-=d;
		else b[nw[i]]-=d;
		sum+=d*g[i][nw[i]];
		match[i][nw[i]]+=d;
	}
	return sum;
}
void km()
{
	ans=0;
	int i,j,u,minn;
	for(i=1;i<=nx;++i)
	for(j=1;j<=ny;++j)
		if(lx[i]<g[i][j]) lx[i]=g[i][j];
	for(u=1;u<=nx;++u)
	while(a[u])
	{
		for(i=1;i<=ny;++i) slack[i]=INF;
		while(a[u])
		{
			for(i=1;i<=nx;++i) sx[i]=0;
			for(i=1;i<=ny;++i) sy[i]=0;
			if(! dfs(u)) break;
			ans+=push(u);
		}
		if(! a[u]) break;
		minn=INF;
		for(i=1;i<=ny;++i)
		if(! sy[i]) minn=min(minn,slack[i]);
		for(i=1;i<=nx;++i) if(sx[i]) lx[i]-=minn;
		for(i=1;i<=ny;++i)
			if(sy[i]) ly[i]+=minn;
			else slack[i]-=minn;
	}
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d",&nx,&ny);
		for(int i=1;i<=nx;++i) scanf("%d",&a[i]);
		for(int i=1;i<=ny;++i) scanf("%d",&b[i]);
		for(int i=1;i<=nx;++i)
		{
			for(int j=1;j<=ny;++j)
			{
				scanf("%d",&g[i][j]);
				g[i][j]=-g[i][j];
				match[i][j]=0;
			}
			nw[i]=lst[i]=ly[i]=0;
			lx[i]=-INF;
		}
		km();
		printf("%d\n",-ans);
	}
	return 0;
}
