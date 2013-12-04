#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 20
int pnt[N][M],son[N],next[N],st[N],dep[N],idx[N];
int root,n;
void init()
{
	idx[0]=idx[1]=0;
	for(int i=2;i<N;i++)
		idx[i]=idx[i-1]+!(i & i-1);
}
int getparent(int x,int len)
{
	while (len>0)
	{
		x=pnt[x][idx[len]];
		len-=1<<idx[len];
	}
	return x;
}
int lca(int u,int v)
{
	int low=0,high=min(dep[u],dep[v]),mid;
	int nu,nv,pu,pv;
	pu=getparent(u,dep[u]-high);
	pv=getparent(v,dep[v]-high);
	if(pu==pv) return pu;
	while (high-low>1)
	{
		mid=idx[high-low-1];
		nu=pnt[pu][mid];
		nv=pnt[pv][mid];
		mid=high-1<<mid;
		if(nu==nv) low=mid;
		else high=mid,pu=nu,pv=nv;
	}
	return pnt[pu][idx[high-low]];
}
void dfs(int u,int d)
{
	st[d]=u;
	dep[u]=d;
	for(int i=2,j=1;i<=d;j++,i*=2)
		pnt[u][j]=st[d-i];
	for(int i=son[u];i;i=next[i])
		dfs(i,d+1);
}
int main()
{
	int tt;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		memset(pnt,0,sizeof(pnt));
		memset(son,0,sizeof(son));
		memset(next,0,sizeof(next));
		for(int i=1;i<n;i++)
		{
			int f,s;
			scanf("%d%d",&f,&s);
			pnt[s][0]=f;
			next[s]=son[f];
			son[f]=s;
		}
		for(int i=1;i<=n;i++)
			if(! pnt[i][0])
			{
				root=i;
				break;
			}
		dfs(root,0);
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}