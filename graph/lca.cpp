#define N 10010
#define M 20
int dis[N],dep[N],pnt[N][M],pre[N];	int p[M];	int n,root;
int head[N],e[N*2],w[N*2],next[N*2],cnt;
void addedge(int u,int v,int val)
{	next[cnt]=head[u];	e[cnt]=v;	w[cnt]=val;	head[u]=cnt++;	}
void init(){	for(int i=0;i<M;i++) p[i]=1<<i;	}
void dfs(int u,int d,int f)
{	dep[u]=d; pre[u]=f;
	for(int i=head[u];i!=-1;i=next[i])	if(e[i]!=f)
	{	dis[e[i]]=dis[u]+w[i];	dfs(e[i],d+1,u);	}
}
void make_pnt()
{	memset(pnt,-1,sizeof(pnt));
	for(int i=1;i<=n;i++) pnt[i][0]=pre[i];
	for(int j=1;p[j]<n;j++)
	for(int i=1;i<=n;i++)	if(pnt[i][j-1]!=-1)	pnt[i][j]=pnt[pnt[i][j-1]][j-1];
}
int lca(int x,int y)
{	int log=0;
	if(dep[x]<dep[y]) swap(x,y);
	while (p[log+1]<=dep[x]) log++;
	for(int i=log;i>=0;i--)	if(dep[x]-p[i]>=dep[y]) x=pnt[x][i];
	if(x==y) return x;
	for(int i=log;i>=0;i--) if(pnt[x][i]!=-1 && pnt[x][i]!=pnt[y][i]) x=pnt[x][i],y=pnt[y][i];
	return pre[x];
}
int main()
{	int tt;	scanf("%d",&tt);	init();
	while (tt--)
	{	scanf("%d",&n);	memset(pre,0,sizeof(pre));	memset(head,-1,sizeof(head));
		cnt=0;
		for(int i=1;i<n;i++)
		{	int u,v;	scanf("%d%d",&u,&v);
			addedge(u,v,1);	addedge(v,u,1);	pre[v]=u;
		}
		for(int i=1;i<=n;i++) if(pre[i]==0) { root=i;	break;	}
		dis[root]=0;	dfs(root,0,0);	make_pnt();	int x,y;
		scanf("%d%d",&x,&y);	printf("%d\n",lca(x,y));
	}
	return 0;
}
//以下两个函数用于求树上两点路径上的最大、小值
void make_rmq()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<M;j++)
		mx[i][j]=-1,mn[i][j]=INF;
	for(int i=1;i<=n;i++) mx[i][0]=mn[i][0]=edg[i];
	for(int j=1;p[j]<n;j++)
	for(int i=1;i<=n;i++)
		if(pnt[i][j-1]!=-1)
		{
			mx[i][j]=max(mx[i][j-1],mx[pnt[i][j-1]][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[pnt[i][j-1]][j-1]);
		}
}
int maxedg,minedg;
void get_rmq(int x,int f)
{
	if(x==f) return;
	int len=dep[x]-dep[f],k=idx[len],id=x;
	for(int j=idx[len-p[k]];j>=0;j--)
		if(p[j] & (len-p[k])) id=pnt[id][j];
   minedg=min(minedg,min(mn[x][k],mn[id][k]));
   maxedg=max(maxedg,max(mx[x][k],mx[id][k]));
}
