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
#include<ctime>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define N 3000010
#define M 200010
struct segmenttree
{
	int l,r,ls,rs,sum;
}tree[M];
int root[N];
int poi,n,m,q;
int a[N],b[N];
int search(int x)
{
	int l=1,r=m,mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if(b[mid]==x) return mid;
		if(b[mid]>x) r=mid-1;
		else l=mid+1;
	}
}
int build(int l,int r)
{
	int k=++poi,mid=(l+r)>>1;
	tree[k].l=l;
	tree[k].r=r;
	tree[k].sum=0;
	if(l==r) return k;
	tree[k].ls=build(l,mid);
	tree[k].rs=build(mid+1,r);
	return k;
}
int rt(int p,int x)
{
	int k=++poi;
	tree[k]=tree[p];
	tree[k].sum=tree[p].sum+1;
	if(tree[p].l==tree[p].r) return k;
	int mid=(tree[p].l+tree[p].r)>>1;
	if(mid>=x) tree[k].ls=rt(tree[p].ls,x);
	else tree[k].rs=rt(tree[p].rs,x);
	return k;
}
int query(int y,int x,int d)
{
	if(tree[y].l==tree[y].r) return tree[y].l;
	int t=tree[tree[y].ls].sum-tree[tree[x].ls].sum;
	if(t>=d) return query(tree[y].ls,tree[x].ls,d);
	return query(tree[y].rs,tree[x].rs,d-t);
}
int main()
{
	while (scanf("%d%d",&n,&q)!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+1+n);
		m=1; poi=0;
		for(int i=2;i<=n;i++)
			if(b[i]!=b[m]) b[++m]=b[i];
		for(int i=1;i<=n;i++)
			a[i]=search(a[i]);
		root[0]=build(1,m);
		for(int i=1;i<=n;i++)
			root[i]=rt(root[i-1],a[i]);
		while (q--)
		{
			int l,r,d;
			scanf("%d%d%d",&l,&r,&d);
			printf("%d\n",b[query(root[r],root[l-1],d)]);
		}
	}
	return 0;
}