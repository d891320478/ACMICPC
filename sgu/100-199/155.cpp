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
#define N 100010
#define M 10010
struct fff
{
	int k,w,id;
}a[N];
int n,tree[N];
int ans[N][3];
int id(int l,int r)
{
	return (l+r) | (l!=r);
}
int cmp(fff a,fff b)
{
	return a.k<b.k;
}
void build(int rt,int l,int r)
{
	if(l==r)
	{
		tree[rt]=l;
		return;
	}
	int m=(l+r)>>1,lc=id(l,m),rc=id(m+1,r);
	build(lc,l,m);
	build(rc,m+1,r);
	if(a[tree[lc]].w<a[tree[rc]].w) tree[rt]=tree[lc];
	else tree[rt]=tree[rc];
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r) return tree[rt];
	int m=(l+r)>>1,lc=id(l,m),rc=id(m+1,r);
	int a1=0,a2=0;
	if(L<=m) a1=query(L,R,l,m,lc);
	if(R>m) a2=query(L,R,m+1,r,rc);
	if(! a1) return a2;
	if(! a2) return a1;
	if(a[a1].w<a[a2].w) return a1;
	else return a2;
}
void solve(int l,int r,int f)
{
	int k=query(l,r,1,n,id(1,n));
	ans[a[k].id][0]=a[f].id;
	if(a[k].k<a[f].k) ans[a[f].id][1]=a[k].id;
	else ans[a[f].id][2]=a[k].id;
	if(l==r) return;
	if(l<=k-1) solve(l,k-1,k);
	if(k+1<=r) solve(k+1,r,k);
}
int main()
{
	while (scanf("%d",&n)!=-1)
	{
		a[0].id=a[0].k=a[0].w=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i].k,&a[i].w);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		build(id(1,n),1,n);
		memset(ans,0,sizeof(ans));
		solve(1,n,0);
		printf("YES\n");
		for(int i=1;i<=n;i++)
			printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	return 0;
}
