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
#define M 10010
int n,ls,lx;
double tree[N<<2],sumc,x[N];
bool lbd[N<<2],rbd[N<<2];
int cnt[N<<2],num[N<<2];
struct segment
{
	double l,r,h;
	int c;
}s[N];
bool cmp(segment a,segment b)
{
	if(a.h==b.h) return a.c>b.c;
	return a.h<b.h;
}
int search(int l,int r,double *a,double x)
{
	int mid;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
}
void push_up(int l,int r,int rt)
{
	if(cnt[rt])
	{
		tree[rt]=x[r]-x[l];
		lbd[rt]=rbd[rt]=1;
		num[rt]=2;
	}
	else if(l+1==r)
	{
		tree[rt]=0;
		lbd[rt]=rbd[rt]=num[rt]=0;
	}
	else
	{
		tree[rt]=tree[rt<<1]+tree[rt<<1|1];
		lbd[rt]=lbd[rt<<1];
		rbd[rt]=rbd[rt<<1|1];
		num[rt]=num[rt<<1]+num[rt<<1|1]-2*lbd[rt<<1|1]*rbd[rt<<1];
	}
}
void update(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l && R>=r)
	{
		cnt[rt]+=c;
		push_up(l,r,rt);
		return;
	}
	int m=(l+r)>>1;
	if(L<m) update(L,R,c,l,m,rt<<1);
	if(R>m) update(L,R,c,m,r,rt<<1|1);
	push_up(l,r,rt);
}
int main()
{
	while (scanf("%d",&n)!=-1)
	{
		ls=0; sumc=0;
		for(int i=1;i<=n;i++)
		{
			double a,b,c,d;
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			x[++ls]=a;
			s[ls]=(segment){a,c,b,1};
			x[++ls]=c;
			s[ls]=(segment){a,c,d,-1};
		}
		sort(x+1,x+1+ls);
		sort(s+1,s+1+ls,cmp);
		lx=1;
		for(int i=2;i<=ls;i++)
			if(x[i]!=x[lx]) x[++lx]=x[i];
		/*for(int i=1;i<=lx;i++)
			printf("%.0lf ",x[i]);
		printf("\n");*/
		memset(cnt,0,sizeof(cnt));
		memset(tree,0,sizeof(tree));
		double last=0;
		for(int i=1;i<=ls;i++)
		{
			int l=search(1,lx,x,s[i].l),r=search(1,lx,x,s[i].r);
			//printf("%.1lf %.1lf %d %d\n",s[i].l,s[i].r,l,r);
			if(l<r) update(l,r,s[i].c,1,lx,1);
			if(i<ls) sumc+=num[1]*(s[i+1].h-s[i].h);
			//printf("%d %lf\n",num[1],tree[1]);
			sumc+=fabs(tree[1]-last);
			last=tree[1];
		}
		printf("%.0lf\n",sumc);
	}
	return 0;
}