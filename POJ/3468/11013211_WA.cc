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
#define N 100010
#define M 10010
int tree[N<<2],lzy[N<<2];
int n,m;
char ch,q;
int x,y,z;
void pushup(int rt)
{
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(int l,int r,int rt)
{
	if(lzy[rt])
	{
		lzy[rt<<1]+=lzy[rt];
 		lzy[rt<<1|1]+=lzy[rt];
 		int m=(l+r)>>1;
 		tree[rt<<1]+=lzy[rt]*(m-l+1);
 		tree[rt<<1|1]+=lzy[rt]*(r-m);
 		lzy[rt]=0;
	}
}
void build(int l,int r,int rt)
{
	tree[rt]=lzy[rt]=0;
	if(l==r) return;
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		tree[rt]+=(r-l+1)*c;
		lzy[rt]+=c;
		return;
	}
	pushdown(l,r,rt);
	int m=(l+r)>>1;
	if(L<=m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
	if(L<=l && R>=r) return tree[rt];
	pushdown(l,r,rt);
	int ans=0,m=(l+r)>>1;
	if(L<=m) ans+=query(L,R,l,m,rt<<1);
	if(R>m) ans+=query(L,R,m+1,r,rt<<1|1);
	pushup(rt);
	return ans;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d%c",&a,&ch);
		update(i,i,a,1,n,1);
	}
	while (m--)
	{
		scanf("%c",&q);
		if(q=='Q')
		{
			scanf(" %d %d%c",&x,&y,&ch);
			printf("%d\n",query(x,y,1,n,1));
		}
		else
		{
			scanf(" %d %d %d%c",&x,&y,&z,&ch);
			update(x,y,z,1,n,1);
		}
	}
	
	return 0;
}