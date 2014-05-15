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
#include<vector>
using namespace std;
#define INF 100000000000LL
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 150010
#define MM 10010
long long n,q;
struct points{ long long x,y,id; }p[NN];
long long ans[NN];
bool cmp1(points a,points b)
{
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	return a.id<b.id;
}
bool cmp2(points a,points b)
{
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y>b.y;
	return a.id<b.id;
}
bool cmp3(points a,points b)
{
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y>b.y;
	return a.id<b.id;
}
bool cmp4(points a,points b)
{
	if(a.x!=b.x) return a.x>b.x;
	if(a.y!=b.y) return a.y<b.y;
	return a.id<b.id;
}
long long Y[NN],ly,tree[NN<<1];
void build(long long l,long long r)
{
	long long rt=IDX(l,r);
	tree[rt]=-INF;
	if(l==r) return;
	long long m=l+r>>1;
	if(l<=m) build(l,m);
	if(r>m) build(m+1,r);
}
void update(long long l,long long r,long long i,long long x)
{
	//if(x<0) printf("%lld\n",x);
	long long rt=IDX(l,r);
	if(l==r)
	{
		tree[rt]=max(tree[rt],x);
		return;
	}
	long long m=l+r>>1;
	if(i<=m) update(l,m,i,x);
	else update(m+1,r,i,x);
	long long rtl=IDX(l,m),rtr=IDX(m+1,r);
	tree[rt]=max(tree[rtl],tree[rtr]);
}
long long query(long long L,long long R,long long l,long long r)
{
	long long rt=IDX(l,r);
	if(L<=l && R>=r) return tree[rt];
	long long m=l+r>>1;
	long long a1=-INF,a2=-INF;
	if(L<=m) a1=query(L,R,l,m);
	if(R>m) a2=query(L,R,m+1,r);
	return max(a1,a2);
}
long long search(long long x)
{
	long long l=0,r=ly-1,mid;
	while (l<=r)
	{
		mid=l+r>>1;
		if(Y[mid]==x) return mid;
		if(Y[mid]<x) l=mid+1;
		else r=mid-1;
	}
}
int main()
{
	long long flag=0;
	while (scanf("%lld",&n) && n!=-1)
	{
		if(! flag) flag=1;
		else printf("\n");
		for(long long i=0;i<n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
			p[i].id=i;
			Y[i]=p[i].y;
		}
		scanf("%lld",&q);
		for(long long i=0;i<q;i++)
		{
			scanf("%lld%lld",&p[i+n].x,&p[i+n].y);
			p[i+n].id=i+n;
			Y[i+n]=p[i+n].y;
			ans[i]=INF;
		}
		sort(Y,Y+n+q);
		ly=1;
		for(long long i=1;i<n+q;i++) if(Y[ly-1]!=Y[i]) Y[ly++]=Y[i];
		sort(p,p+n+q,cmp1);
		build(1,ly);
		for(long long i=0;i<n+q;i++)
		{
			long long zz=search(p[i].y)+1;
			if(p[i].id<n) update(1,ly,zz,p[i].x+p[i].y);
			else ans[p[i].id-n]=min(ans[p[i].id-n],ABS(query(1,zz,1,ly)-(p[i].x+p[i].y)));
		}
		sort(p,p+n+q,cmp2);
		build(1,ly);
		for(long long i=0;i<n+q;i++)
		{
			long long zz=search(p[i].y)+1;
			if(p[i].id<n) update(1,ly,zz,-(p[i].x+p[i].y));
			else ans[p[i].id-n]=min(ans[p[i].id-n],ABS(-query(zz,ly,1,ly)-(p[i].x+p[i].y)));
		}
		sort(p,p+n+q,cmp3);
		build(1,ly);
		for(long long i=0;i<n+q;i++)
		{
			long long zz=search(p[i].y)+1;
			if(p[i].id<n) update(1,ly,zz,p[i].x-p[i].y);
			else ans[p[i].id-n]=min(ans[p[i].id-n],ABS(query(zz,ly,1,ly)-(p[i].x-p[i].y)));
		}
		sort(p,p+n+q,cmp4);
		build(1,ly);
		for(long long i=0;i<n+q;i++)
		{
			long long zz=search(p[i].y)+1;
			if(p[i].id<n) update(1,ly,zz,-(p[i].x-p[i].y));
			else ans[p[i].id-n]=min(ans[p[i].id-n],ABS(-query(1,zz,1,ly)-(p[i].x-p[i].y)));
		}
		for(long long i=0;i<q;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}

