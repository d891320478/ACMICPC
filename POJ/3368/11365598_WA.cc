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
	if(tree[rtl].ls==m-l+1) if(a[m]==a[m+1]) tree[rt].ls+=tree[rtr].ls;
	tree[rt].rs=tree[rtr].rs;
	if(tree[rtr].rs==r-m) if(a[m]==a[m+1]) tree[rt].rs+=tree[rtl].rs;
	tree[rt].ss=max(tree[rtl].ss,tree[rtr].ss);
	if(a[m]==a[m+1]) tree[rt].ss=max(tree[rt].ss,tree[rtl].rs+tree[rtr].ls);
}
int ans;
void query(int L,int R,int l,int r)
{
	int rt=IDX(l,r),m=(l+r)>>1;
	if(L<=l && R>=r)
	{
		ans=max(ans,tree[rt].ss);
		return;
	}
	int rtl=IDX(l,m),rtr=IDX(m+1,r);
	if(L<=m) query(L,R,l,m);
	if(R>m) query(L,R,m+1,r);
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
			ans=0;
			query(l,r,1,n);
			printf("%d\n",ans);
		}
	}
	return 0;
}