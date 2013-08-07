#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:200000000")
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define N 50010
int n,m,q;
int head[N],next[N<<1],e[N<<1],cnt;
int dep[N],sz[N],pnt[N],heavy[N],rev[N],num[N];
int poi;
int tree[N<<1],lzy[N<<1],a[N];
int find(int x){ return x==pnt[x]?pnt[x]:pnt[x]=find(pnt[x]); }
void addedge(int u,int v){ next[cnt]=head[u]; e[cnt]=v; head[u]=cnt++; }
void dfs(int u,int f)
{
	int v,mx=-1;
	sz[u]=1;
	heavy[u]=-1;
	for(int i=head[u];i!=-1;i=next[i])
	if((v=e[i])!=f)
	{
		dep[v]=dep[u]+1;
		rev[v]=i^1;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>mx)
		{
			mx=sz[v];
			heavy[u]=i;
		}
	}
	if(heavy[u]!=-1) pnt[e[heavy[u]]]=u;
}
void pushup(int l,int r)
{
	int rt=IDX(l,r),mid=l+r>>1;
	int rtl=IDX(l,mid),rtr=IDX(mid+1,r);
	tree[rt]=tree[rtl]+tree[rtr];
}
void pushdown(int l,int r)
{
	int rt=IDX(l,r),mid=l+r>>1;
	int rtl=IDX(l,mid),rtr=IDX(mid+1,r);
	if(lzy[rt])
	{
		lzy[rtl]+=lzy[rt];
		tree[rtl]+=lzy[rt]*(mid-l+1);
		lzy[rtr]+=lzy[rt];
		tree[rtr]+=lzy[rt]*(r-mid);
		lzy[rt]=0;
	}
}
void update(int i,int x,int l,int r)
{
	if(l==r)
	{
		int rt=IDX(l,r);
		tree[rt]+=x;
		return;
	}
	int mid=l+r>>1;
	pushdown(l,r);
	if(i<=mid) update(i,x,l,mid);
	else update(i,x,mid+1,r);
	pushup(l,r);
}
void update(int L,int R,int w,int l,int r)
{
	if(L<=l && R>=r)
	{
		int rt=IDX(l,r);
		tree[rt]+=(r-l+1)*w;
		lzy[rt]+=w;
		return;
	}
	int mid=l+r>>1;
	pushdown(l,r);
	if(L<=mid) update(L,R,w,l,mid);
	if(R>mid) update(L,R,w,mid+1,r);
	pushup(l,r);
}
int query(int i,int l,int r)
{
	if(l==r)
	{
		int rt=IDX(l,r);
		return tree[rt];
	}
	int mid=l+r>>1;
	pushdown(l,r);
	if(i<=mid) return query(i,l,mid);
	return query(i,mid+1,r);
}
void change(int u,int lca,int w)
{
	while (dep[u]>=dep[lca])
	{
		int p=pnt[u];
		if(dep[p]<dep[lca]) p=lca;
		update(num[u],num[p],w,1,n);
		u=e[rev[p]];
	}
}
void init()
{
	memset(num,-1,sizeof(num));
	memset(heavy,-1,sizeof(heavy));
	memset(tree,0,sizeof(tree));
	memset(lzy,0,sizeof(lzy));
	dep[0]=-1;
	poi=0;
	for(int i=1;i<=n;++i) pnt[i]=i;
	dfs(0,-1);
	pnt[1]=1;
	for(int i=1;i<=n;++i)
	if(heavy[i]==-1)
	{
		int pos=i;
		while (pos && pos==e[heavy[e[rev[pos]]]])
		{
			int t=rev[pos];
			num[pos]=++poi;
			update(num[pos],a[pos],1,n);
			pos=e[rev[pos]];
		}
		if(pos)
		{
			num[pos]=++poi;
			update(num[pos],a[pos],1,n);
		}
	}
}
int lca(int u,int v)
{
	while (1)
	{
		int a=find(u),b=find(v);
		if(a==b) return dep[u]<dep[v]?u:v;
		if(dep[a]>=dep[b]) u=e[rev[a]];
		else v=e[rev[b]];
	}
}
void ids(int u,int v,int w)
{
	int p=lca(u,v);
	change(u,p,w);
	change(v,p,w);
	change(p,p,-w);
}
char ord[3];
int u,v,w;
int main ()
{
freopen("1.in","r",stdin);
	while (scanf("%d%d%d",&n,&m,&q)!=-1)
	{
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		cnt=0;
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		addedge(0,1);
		addedge(1,0);
		init();
		while (q--)
		{
			scanf("%s",ord);
			if(ord[0]=='I' || ord[0]=='D')
			{
				scanf("%d%d%d",&u,&v,&w);
				if(ord[0]=='D') w=-w;
				ids(u,v,w);
			}
			else
			{
				scanf("%d",&u);
				printf("%d\n",query(num[u],1,n));
			}
		}
	}
	return 0;
}
