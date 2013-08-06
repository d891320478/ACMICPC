//POJ 3237
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 100010
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define INF (1<<30)
int n;
int head[N],cnt;
struct edge
{
	int v,w,next;
}e[N<<1];
int dep[N],sz[N],pnt[N],heavy[N],rev[N],num[N<<1];
int poi;
struct sgt
{
	int mx,mn,lzy;
}tree[N<<1];
int find(int x){ return x==pnt[x]?x:pnt[x]=find(pnt[x]); }
void addedge(int u,int v,int w)
{
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt++;
}
void dfs(int u,int f)
{
	int v,mx=-1;
	sz[u]=1;
	heavy[u]=-1;
	for(int i=head[u];i!=-1;i=e[i].next)
	if((v=e[i].v)!=f)
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
	if(heavy[u]!=-1) pnt[e[heavy[u]].v]=u;
}
void pushup(int l,int r)
{
	int rt=IDX(l,r),mid=l+r>>1;
	int rtl=IDX(l,mid),rtr=IDX(mid+1,r);
	tree[rt].mx=max(tree[rtl].mx,tree[rtr].mx);
	tree[rt].mn=min(tree[rtl].mn,tree[rtr].mn);
}
void make(int rt)
{
	int tmp=-tree[rt].mx;
	tree[rt].mx=-tree[rt].mn;
	tree[rt].mn=tmp;
}
void pushdown(int l,int r)
{
	int rt=IDX(l,r),mid=l+r>>1;
	int rtl=IDX(l,mid),rtr=IDX(mid+1,r);
	if(tree[rt].lzy)
	{
		tree[rtl].lzy^=1;
		tree[rtr].lzy^=1;
		make(rtl);
		make(rtr);
		tree[rt].lzy=0;
	}
}
void build(int l,int r)
{
	int rt=IDX(l,r);
	tree[rt].mx=-INF;
	tree[rt].mn=INF;
	tree[rt].lzy=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid);
	build(mid+1,r);
}
void update(int x,int w,int l,int r)
{
	int rt=IDX(l,r);
	if(l==r)
	{
		tree[rt].mx=tree[rt].mn=w;
		return;
	}
	pushdown(l,r);
	int mid=l+r>>1;
	if(x<=mid) update(x,w,l,mid);
	else update(x,w,mid+1,r);
	pushup(l,r);
}
void reverse(int L,int R,int l,int r)
{
	int rt=IDX(l,r);
	if(L<=l && R>=r)
	{
		make(rt);
		tree[rt].lzy^=1;
		return;
	}
	pushdown(l,r);
	int mid=l+r>>1;
	if(L<=mid) reverse(L,R,l,mid);
	if(R>mid) reverse(L,R,mid+1,r);
	pushup(l,r);
}
int query(int L,int R,int l,int r)
{
	int rt=IDX(l,r);
	if(L<=l && R>=r) return tree[rt].mx;
	pushdown(l,r);
	int mid=l+r>>1,ret=-INF;
	if(L<=mid) ret=max(ret,query(L,R,l,mid));
	if(R>mid) ret=max(ret,query(L,R,mid+1,r));
	return ret;
}
int queryuv(int u,int lca)
{
	int ans=-INF;
	while (u!=lca)
	{
		int ed=rev[u];
		if(num[ed]==-1)
		{
			ans=max(ans,e[ed].w);
			u=e[ed].v;
		}
		else
		{
			int p=pnt[u];
			if(dep[p]<dep[lca]) p=lca;
			ans=max(ans,query(num[ed],num[heavy[p]],1,n-1));
			u=p;
		}
	}
	return ans;
}
void init()
{
	build(1,n-1);
	memset(num,-1,sizeof(num));
	dep[1]=poi=0;
	for(int i=1;i<=n;++i) pnt[i]=i;
	dfs(1,0);
	for(int i=1;i<=n;++i)
	if(heavy[i]==-1)
	{
		int pos=i;
		while (pos!=1 && e[heavy[e[rev[pos]].v]].v==pos)
		{
			int t=rev[pos];
			num[t]=num[t^1]=++poi;
			update(num[t],e[t].w,1,n-1);
			pos=e[t].v;
		}
	}
}
void change(int edge,int val)
{
	if(num[edge]==-1) e[edge].w=e[edge^1].w=val;
	else update(num[edge],val,1,n-1);
}
void NGT(int u,int lca)
{
	while (u!=lca)
	{
		int ed=rev[u];
		if(num[ed]==-1)
		{
			e[ed].w=e[ed^1].w=-e[ed].w;
			u=e[ed].v;
		}
		else
		{
			int p=pnt[u];
			if(dep[p]<dep[lca]) p=lca;
			reverse(num[ed],num[heavy[p]],1,n-1);
			u=p;
		}
	}
}
int lca(int u,int v)
{
	while (1)
	{
		int a=find(u),b=find(v);
		if(a==b) return dep[u]<dep[v]?u:v;
		else if(dep[a]>=dep[b]) u=e[rev[a]].v;
		else v=e[rev[b]].v;
	}
}
int solve(int u,int v)
{
	int p=lca(u,v);
	return max(queryuv(u,p),queryuv(v,p));
}
void _negate(int u,int v)
{
	int p=lca(u,v);
	NGT(u,p); NGT(v,p);
}
int main ()
{
freopen("1.in","r",stdin);
	int tt;
	int u,v,w;
	char s[15];
	scanf("%d",&tt);
	while (tt--)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		scanf("%d",&n);
		for(int i=1;i<n;++i)
		{			
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		init();
		while (scanf("%s",s))
		{
			if(s[0]=='D') break;
			if(s[0]=='Q')
			{
				scanf("%d%d",&u,&v);
				printf("%d\n",solve(u,v));
			}
			else if(s[0]=='C')
			{
				scanf("%d%d",&u,&w);
				change((u-1)<<1,w);
			}
			else
			{
				scanf("%d%d",&u,&v);
				_negate(u,v);
			}
		}
	}
	return 0;
}
