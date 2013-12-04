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
long long tree[N<<2],lzy[N<<2];
long long n,m;
char ch,q;
long long x,y,z;
void pushup(long long rt)
{
	tree[rt]=tree[rt<<1]+tree[rt<<1|1];
}
void pushdown(long long l,long long r,long long rt)
{
	if(lzy[rt])
	{
		lzy[rt<<1]+=lzy[rt];
 		lzy[rt<<1|1]+=lzy[rt];
 		long long m=(l+r)/2;
 		tree[rt<<1]+=lzy[rt]*(m-l+1);
 		tree[rt<<1|1]+=lzy[rt]*(r-m);
 		lzy[rt]=0;
	}
}
void build(long long l,long long r,long long rt)
{
	tree[rt]=lzy[rt]=0;
	if(l==r) return;
	long long m=(l+r)/2;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
}
void update(long long L,long long R,long long c,long long l,long long r,long long rt)
{
	if(L<=l && R>=r)
	{
		tree[rt]+=(r-l+1)*c;
		lzy[rt]+=c;
		return;
	}
	pushdown(l,r,rt);
	long long m=(l+r)/2;
	if(L<=m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
long long query(long long L,long long R,long long l,long long r,long long rt)
{
	if(L<=l && R>=r) return tree[rt];
	pushdown(l,r,rt);
	long long ans=0,m=(l+r)/2;
	if(L<=m) ans+=query(L,R,l,m,rt<<1);
	if(R>m) ans+=query(L,R,m+1,r,rt<<1|1);
	pushup(rt);
	return ans;
}
int main ()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	{
		long long a;
		scanf("%lld%c",&a,&ch);
		update(i,i,a,1,n,1);
	}
	while (m--)
	{
		scanf("%c",&q);
		if(q=='Q')
		{
			scanf(" %lld %lld%c",&x,&y,&ch);
			printf("%lld\n",query(x,y,1,n,1));
		}
		else
		{
			scanf(" %lld %lld %lld%c",&x,&y,&z,&ch);
			update(x,y,z,1,n,1);
		}
	}
	
	return 0;
}