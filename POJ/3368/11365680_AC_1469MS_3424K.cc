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
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 100010
#define MM 10010
struct segmenttree
{
	int ls,rs,ss;
}tree[NN<<1];
int n,m,a[NN];
void build(int l,int r)
{
	int rt=IDX(l,r),m=(l+r)>>1;
	if(l==r)
	{
		tree[rt].ls=tree[rt].rs=tree[rt].ss=1;
		return;
	}
	int rtl=IDX(l,m),rtr=IDX(m+1,r);
	if(l<=m) build(l,m);
	if(r>m) build(m+1,r);
	tree[rt].ls=tree[rtl].ls;
	tree[rt].rs=tree[rtr].rs;
	tree[rt].ss=max(tree[rtl].ss,tree[rtr].ss);
	if(a[m]==a[m+1])
	{
		if(tree[rtl].ls==m-l+1) tree[rt].ls+=tree[rtr].ls;
		if(tree[rtr].rs==r-m) tree[rt].rs+=tree[rtl].rs;
		tree[rt].ss=max(tree[rt].ss,tree[rtl].rs+tree[rtr].ls);
	}
}
int query(int L,int R,int l,int r)
{
	int rt=IDX(l,r),m=(l+r)>>1;
	if(L<=l && R>=r) return tree[rt].ss;
	int rtl=IDX(l,m),rtr=IDX(m+1,r),a1=-1,a2=-1;
	if(L<=m) a1=query(L,R,l,m);
	if(R>m) a2=query(L,R,m+1,r);
	if(a1==-1) return a2;
	if(a2==-1) return a1;
	if(a[m]==a[m+1]) return max(max(a1,a2),min(tree[rtl].rs,m-L+1)+min(tree[rtr].ls,R-m));
	else return max(a1,a2);
}
int main()
{
	while (scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		build(1,n);
		while (m--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r,1,n));
		}
	}
	return 0;
}