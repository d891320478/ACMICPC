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
#define N 80010
#define M 10010
struct segmenttree
{
	int ls,rs,ss;
}tree[N<<2];
int lzy[N<<2],flag;
void build(int l,int r,int rt)
{
	lzy[rt]=0;
	tree[rt].ls=tree[rt].rs=tree[rt].ss=r-l+1;
	if(l==r) return;
	int m=(l+r)>>1;
	if(l<=m) build(l,m,rt<<1);
	if(r>m) build(m+1,r,rt<<1|1);
}
void push_up(int l,int r,int rt)
{
	int m=(l+r)>>1;
	tree[rt].ls=tree[rt<<1].ls;
	if(tree[rt<<1].ls==m-l+1) tree[rt].ls+=tree[rt<<1|1].ls;
	tree[rt].rs=tree[rt<<1|1].rs;
	if(tree[rt<<1|1].ls==r-m) tree[rt].rs+=tree[rt<<1].rs;
	tree[rt].ss=max(tree[rt<<1].ss,tree[rt<<1|1].ss);
	tree[rt].ss=max(tree[rt<<1].rs+tree[rt<<1|1].ls,tree[rt].ss);
}
void push_down(int l,int r,int rt)
{
	int m=(l+r)>>1;
	if(lzy[rt]==1)
	{
		tree[rt<<1].ls=tree[rt<<1].rs=tree[rt<<1].ss=m-l+1;
		tree[rt<<1|1].ls=tree[rt<<1|1].rs=tree[rt<<1|1].ss=r-m;
		lzy[rt]=0;
		lzy[rt<<1]=lzy[rt<<1|1]=1;
	}
	if(lzy[rt]==2)
	{
		tree[rt<<1].ls=tree[rt<<1].rs=tree[rt<<1].ss=0;
		tree[rt<<1|1].ls=tree[rt<<1|1].rs=tree[rt<<1|1].ss=0;
		lzy[rt]=0;
		lzy[rt<<1]=lzy[rt<<1|1]=2;
	}
}
void update(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		lzy[rt]=1;
		tree[rt].ls=tree[rt].rs=tree[rt].ss=r-l+1;
		return;
	}
	int m=(l+r)>>1;
	push_down(l,r,rt);
	if(L<=m) update(L,R,l,m,rt<<1);
	if(R>m) update(L,R,m+1,r,rt<<1|1);
	push_up(l,r,rt);
}
void query(int qlr,int d,int l,int r,int rt)
{
	if(r-l+1<=d)
	{
		lzy[rt]=2;
		tree[rt].ls=tree[rt].rs=tree[rt].ss=0;
		flag=min(flag,l);
		return;
	}
	int m=(l+r)>>1;
	push_down(l,r,rt);
	if(qlr==0)
	{
		if(tree[rt<<1].ss>=d) query(0,d,l,m,rt<<1);
		else if(tree[rt<<1].rs+tree[rt<<1|1].ls>=d)
		{
			int dd=d-tree[rt<<1].rs;
			query(2,tree[rt<<1].rs,l,m,rt<<1);
			query(1,dd,m+1,r,rt<<1|1);
		}
		else query(0,d,m+1,r,rt<<1|1);
	}
	else
	if(qlr==1)
	{
		if(tree[rt<<1].ls>=d) query(1,d,l,m,rt<<1);
		else
		{
			int dd=d-tree[rt<<1].ls;
			query(1,tree[rt<<1].ls,l,m,rt<<1);
			query(1,dd,m+1,r,rt<<1|1);
		}
	}
	else
	{
		if(tree[rt<<1|1].rs>=d) query(2,d,m+1,r,rt<<1|1);
		else
		{
			int dd=d-tree[rt<<1|1].rs;
			query(2,tree[rt<<1|1].rs,m+1,r,rt<<1|1);
			query(2,dd,l,m,rt<<1);
		}
	}
	push_up(l,r,rt);
}
void print(int l,int r,int rt)
{
	printf("%d %d %d %d %d\n",l,r,tree[rt].ls,tree[rt].rs,tree[rt].ss);
	if(l==r) return;
	int m=(l+r)>>1;
	print(l,m,rt<<1);
	print(m+1,r,rt<<1|1);
}
int n,m;
int ord,l,r,d;
int main()
{
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while (m--)
	{
		scanf("%d",&ord);
		if(ord==1)
		{
			scanf("%d",&d);
			if(tree[1].ss<d)
			{
				printf("0\n");
				continue;
			}
			flag=n+1;
			query(0,d,1,n,1);
			printf("%d\n",flag);
		}
		else
		{
			scanf("%d %d",&l,&r);
			update(l,l+r-1,1,n,1);
		}
		//print(1,n,1); printf("\n");
	}
	return 0;
}