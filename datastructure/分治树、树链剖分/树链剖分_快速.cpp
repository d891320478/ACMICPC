#define N 80010
int n,m,a[N];
int head[N],cnt,next[N<<1],e[N<<1];
void addedge(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int dep[N],sz[N],heavy[N],rev[N],root[N],pnt[N];
int sgt;
struct segmenttree
{
	int ls,rs,rt,l,r;
}tree[N<<2];
struct SBT
{
	int l,r,key,sz;
	void newsbt(int ins)
	{		key=ins;		sz=1;		l=r=0;	}
}sbt[N*25];
int la;
void SBTr(int &x)//右旋
{
	int y=sbt[x].l;
	sbt[x].l=sbt[y].r;		sbt[y].r=x;	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;		x=y;
}
void SBTl(int &x)//左旋
{
	int y=sbt[x].r;
	sbt[x].r=sbt[y].l;		sbt[y].l=x;	sbt[y].sz=sbt[x].sz;
	sbt[x].sz=sbt[sbt[x].l].sz+sbt[sbt[x].r].sz+1;		x=y;
}
void maintain(int &t,bool flag)//维护
{
	if(! flag)
	{
		if(sbt[sbt[sbt[t].l].l].sz>sbt[sbt[t].r].sz) SBTr(t);
		else if(sbt[sbt[sbt[t].l].r].sz>sbt[sbt[t].r].sz)
		{			SBTl(sbt[t].l);			SBTr(t);		}
		else return;
	}
	else
	{
		if(sbt[sbt[sbt[t].r].r].sz>sbt[sbt[t].l].sz) SBTl(t);
		else if(sbt[sbt[sbt[t].r].l].sz>sbt[sbt[t].l].sz)
		{			SBTr(sbt[t].r);			SBTl(t);		}
		else return;
	}
	maintain(sbt[t].l,0);		maintain(sbt[t].r,1);
	maintain(t,0);		maintain(t,1);
}
void SBTinsert(int &t,int v)//插入
{
	if(t==0){	t=++la;		sbt[t].newsbt(v);		return;	}
	sbt[t].sz++;
	if(v<sbt[t].key) SBTinsert(sbt[t].l,v);
	else SBTinsert(sbt[t].r,v);
	maintain(t,v>=sbt[t].key);
}
int SBTdel(int &t,int v)//删除
{
	sbt[t].sz--;
	if(v==sbt[t].key || v<sbt[t].key && !sbt[t].l || v>sbt[t].key && !sbt[t].r)
	{
		if(sbt[t].l && sbt[t].r)
		{	int p=SBTdel(sbt[t].l,v+1);		sbt[t].key=sbt[p].key;	return p;	}
		else
		{	int p=t;	t=sbt[t].l+sbt[t].r;	return p;		}
	}
	else return SBTdel(v<sbt[t].key?sbt[t].l:sbt[t].r,v);
}
int SBTrank(int t,int v)
{
	if(! t) return 0;
	if(v<sbt[t].key) return SBTrank(sbt[t].l,v);
	return sbt[sbt[t].l].sz+1+SBTrank(sbt[t].r,v);
}
void dfs(int u,int f)
{
	int mx=-1,eu=-1,v;
	sz[u]=1;
	for(int i=head[u];i!=-1;i=next[i])
	if(e[i]!=f)
	{
		v=e[i];
		dep[v]=dep[u]+1;
		rev[v]=i^1;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>mx)
		{
			mx=sz[v];
			eu=i;
		}
	}
	heavy[u]=eu;
	if(eu!=-1) pnt[e[eu]]=u;
}
int build(int l,int r)
{
	int k=++sgt;
	tree[k].rt=0;
	tree[k].l=l;
	tree[k].r=r;
	if(l==r) return k;
	int mid=l+r>>1;
	tree[k].ls=build(l,mid);
	tree[k].rs=build(mid+1,r);
	return k;
}
int find(int x)
{
	return x==pnt[x]?pnt[x]:pnt[x]=find(pnt[x]);
}
void update(int i,int w,int rt)
{
	SBTinsert(tree[rt].rt,w);
	if(tree[rt].l==tree[rt].r) return;
	int mid=tree[rt].l+tree[rt].r>>1;
	if(i<=mid) update(i,w,tree[rt].ls);
	else update(i,w,tree[rt].rs);
}
void erase(int i,int w,int rt)
{
	SBTdel(tree[rt].rt,w);
	if(tree[rt].l==tree[rt].r) return;
	int mid=tree[rt].l+tree[rt].r>>1;
	if(i<=mid) erase(i,w,tree[rt].ls);
	else erase(i,w,tree[rt].rs);
}
int query(int L,int R,int w,int rt)
{
	if(L<=tree[rt].l && R>=tree[rt].r) return SBTrank(tree[rt].rt,w);
	int mid=tree[rt].l+tree[rt].r>>1,ret=0;
	if(L<=mid) ret+=query(L,R,w,tree[rt].ls);
	if(R>mid) ret+=query(L,R,w,tree[rt].rs);
	return ret;
}
void init()
{
	sgt=0;
	memset(tree,0,sizeof(tree));
	for(int i=1;i<=n;++i) pnt[i]=i;
	dep[0]=-1;
	dfs(0,-1);
	pnt[1]=1;
	for(int i=1;i<=n;++i)
	if(heavy[i]==-1)
	{
		int poi=0;
		int pos=i;
		while (pos && pos==e[heavy[e[rev[pos]]]])
		{
			++poi;
			root[pos]=sgt+1;
			pos=e[rev[pos]];
		}
		if(pos) ++poi,root[pos]=sgt+1;
		build(1,poi);
	}
	for(int i=1;i<=n;++i)
		update(dep[i]-dep[find(i)]+1,a[i],root[i]);
}
int lca(int u,int v)
{
	while (1)
	{
		int a=pnt[u],b=pnt[v];
		if(a==b) return dep[u]<dep[v]?u:v;
		if(dep[a]>=dep[b]) u=e[rev[a]];
		else v=e[rev[b]];
	}
}
int queryuv(int u,int lca,int w)
{
	int ans=0;
	while (dep[u]>=dep[lca])
	{
		int p=pnt[u];
		if(dep[p]<dep[lca]) p=lca;
		ans+=query(dep[p]-dep[pnt[u]]+1,dep[u]-dep[pnt[u]]+1,w,root[u]);
		u=e[rev[p]];
	}
	return ans;
}
int main ()
{
	cnt=la=0;
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<n;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	addedge(0,1);
	addedge(1,0);
	init();
	int ord,u,v,sum=0;
	while (m--)
	{
		scanf("%d%d%d",&ord,&u,&v);
		if(ord==0)
		{
			erase(dep[u]-dep[pnt[u]]+1,a[u],root[u]);
			a[u]=v;
			update(dep[u]-dep[pnt[u]]+1,a[u],root[u]);
		}
		else
		{
			int p=lca(u,v);
			if(ord>dep[u]+dep[v]-2*dep[p]+1) printf("invalid request!\n");
			else
			{
				ord=dep[u]+dep[v]-2*dep[p]+1-ord+1;
				int l=0,r=100000000,mid;
				while (l<r)
				{
					mid=l+r>>1;
					if(queryuv(u,p,mid)+queryuv(v,p,mid)-(a[p]<=mid)<ord) l=mid+1;
					else r=mid;
				}
				printf("%d\n",l);
			}
		}
	}
	return 0;
}
