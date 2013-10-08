#include <cstdio>
#include <cstring>
#include <iostream>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define N 100010
int trie[20*N][2],root[N],lt,sum[20*N];
int head[N],next[N<<1],e[N<<1],cnt;
int n,m,a[N];
void add(int u,int v)
{
	next[cnt]=head[u];
	e[cnt]=v;
	head[u]=cnt++;
}
int newnode()
{
	trie[lt][0]=trie[lt][1]=0;
	sum[lt]=0;
	return lt++;
}
void insert(int x,int y,int val)
{
	for(int i=0;i<16;++i)
	{
		int c=(val>>(15-i))&1;
		if(! trie[x][c])
		{
			trie[x][c]=newnode();
			trie[x][!c]=trie[y][!c];
			sum[trie[x][!c]]=sum[trie[x][!c]];
		}
		sum[trie[x][c]]=sum[trie[y][c]]+1;
		x=trie[x][c];
		y=trie[y][c];
	}
}
int sz[N],rev[N],pnt[N],dep[N];
void dfs(int u,int f)
{
	int v,mx=-1,he=-1;
	sz[u]=1;
	root[u]=newnode();
	insert(root[u],root[f],a[u]);
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
			he=i;
		}
	}
	if(he!=-1) pnt[e[he]]=u;
}
int find(int u)
{
	return u==pnt[u]?u:pnt[u]=find(pnt[u]);
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
int query(int x,int y,int z,int w)
{
	int res=w^a[z],ans=0;
	x=root[x];
	y=root[y];
	z=root[z];
	for(int i=0;i<16;++i)
	{
		int c=(w>>(15-i))&1;
		if(sum[trie[x][!c]]+sum[trie[y][!c]]-2*sum[trie[z][!c]]>0)
		{
			x=trie[x][!c];
			y=trie[y][!c];
			z=trie[z][!c];
			ans|=1<<(15-i);
		}
		else
		{
			x=trie[x][c];
			y=trie[y][c];
			z=trie[z][c];
		}
	}
	return max(res,ans);
}
void init()
{
	cnt=0;
	lt=1;
	memset(head,-1,sizeof(head));
	dep[1]=0;
	for(int i=1;i<=n;++i)
		pnt[i]=i;
}
int main ()
{
freopen("1.in","r",stdin);
	while (scanf("%d%d",&n,&m)!=-1)
	{
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		init();
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
		}
		dfs(1,0);
		while (m--)
		{
			int u,v,la,w;
			scanf("%d%d%d",&u,&v,&w);
			la=lca(u,v);
			printf("%d\n",query(u,v,la,w));
		}
	}
	return 0;
}
