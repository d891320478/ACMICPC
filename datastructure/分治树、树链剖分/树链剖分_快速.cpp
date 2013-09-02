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
