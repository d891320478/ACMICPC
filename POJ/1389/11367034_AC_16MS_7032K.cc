#include<cstdio>
#include<cstring>
#include<iostream>
#include <algorithm>
using namespace std;
#define INF (1<<30)
#define EPS 1e-6
#define PI acos(-1)
#define lowbit(x) ((x) & (-(x)))
#define IDX(l,r) ((l)+(r) | (l)!=(r))
#define ABS(x) ((x)>0?(x):-(x))
#define SET(a,b) memset(a,b,sizeof(a))
#define NN 200010
#define MM 10010
struct point{ double x,y; };
double xmult(point p0,point p1,point p2)
{ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
int n;
int cnt[NN<<2],tree[NN<<2],area,xa[NN],ls,lx;
struct segment
{
	int l,r,h,c;
}s[NN];
bool cmp(segment a,segment b)
{
	return a.h<b.h;
}
int search(int l,int r,int *a,int x)
{
	int mid;
	while (l<=r)
	{
		mid=l+r>>1;
		if(a[mid]==x) return mid;
		if(a[mid]<x) l=mid+1;
		else r=mid-1;
	}
}
void push_up(int l,int r,int rt)
{
	if(cnt[rt]) tree[rt]=xa[r]-xa[l];
	else if(l+1==r) tree[rt]=0;
	else tree[rt]=tree[rt<<1]+tree[rt<<1|1];
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
	while (1)
	{
		n=area=ls=0;
		while (1)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(a==-1 && b==-1 && c==-1 && d==-1) break;
			xa[++ls]=a; s[ls]=(segment){a,c,b,1};
			xa[++ls]=c; s[ls]=(segment){a,c,d,-1};
			n++;
		}
		if(n==0) break;
		sort(xa+1,xa+1+ls);
		sort(s+1,s+1+ls,cmp);
		lx=1;
		for(int i=2;i<=ls;i++)
			if(xa[i]!=xa[lx]) xa[++lx]=xa[i];
		memset(tree,0,sizeof(tree));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<ls;i++)
		{
			int l=search(1,lx,xa,s[i].l),r=search(1,lx,xa,s[i].r);
			if(l<r) update(l,r,s[i].c,1,lx,1);
			area+=tree[1]*(s[i+1].h-s[i].h);
		}
		printf("%d\n",area);
	}
	return 0;
}