#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 40010
int n;
int x[N],y[N];
int a[M],b[M],la;
int tree[M<<2],lzy[M<<2];
int search(int l,int r,int x)
{
 	int mid;
 	while (l<=r)
 	{
 		mid=(l+r)>>1;
 		if(b[mid]==x) return mid;
 		if(b[mid]<x) l=mid+1;
 		else r=mid-1;
 	}
 	return -1;
}
void pushup(int rt)
{
	tree[rt]=tree[rt<<1] && tree[rt<<1|1];
}
void pushdown(int l,int r,int rt)
{
	if(lzy[rt])
	{
		lzy[rt<<1]=lzy[rt<<1|1]=1;
		tree[rt<<1]=tree[rt<<1|1]=1;
		lzy[rt]=0;
	}
}
void update(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		lzy[rt]=1;
		tree[rt]=1;
		return;
	}
	pushdown(l,r,rt);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,l,m,rt<<1);
	if(R>m) update(L,R,m+1,r,rt<<1|1);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r) return tree[rt];
	pushdown(l,r,rt);
	int ans=1,m=(l+r)>>1;
	if(L<=m) if(! query(L,R,l,m,rt<<1)) ans=0;
	if(R>m) if(! query(L,R,m+1,r,rt<<1|1)) ans=0;
	pushup(rt);
	return ans;
}
int main ()
{
	int tt,i;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		memset(tree,0,sizeof(tree));
		memset(lzy,0,sizeof(lzy));
		a[0]=b[0]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			a[++a[0]]=x[i];
			a[++a[0]]=y[i];
		}
		sort(a+1,a+1+a[0]); la=a[0]; a[0]=1;
		for(i=2;i<=la;i++)
			if(a[i]!=a[i-1]) a[++a[0]]=a[i];
		for(i=1;i<a[0];i++)
		{
			b[++b[0]]=a[i];
			if(a[i+1]-a[i]>2)
			{
				b[++b[0]]=a[i]+1;
				b[++b[0]]=a[i+1]-1;
			}
			else
			if(a[i+1]-a[i]>1) b[++b[0]]=a[i]+1;
		}
		b[++b[0]]=a[a[0]];
		//for(i=1;i<=b[0];i++) printf("%d ",b[i]);
		//continue;
		int ans=0;
		for(i=n;i>0;i--)
		{
			int u=search(1,b[0],x[i]),v=search(1,b[0],y[i]);
			if(! query(u,v,1,b[0],1))
			{
				ans++;
				update(u,v,1,b[0],1);
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}