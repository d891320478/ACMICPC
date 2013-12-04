#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 1024
#define pi 3.141592653
#define MAKE_VECTOR(p1,p2) (struct node){p[p2].x-p[p1].x,p[p2].y-p[p1].y}
struct node
{
	int x,y;
}p[N];
int h[N],np;
int d[N*2],top,bot;
int n,L;

int cmp(const node &a,const node &b)
{
	if(a.y<b.y)return 1;
	if(a.y>b.y)return 0;
	if(a.x<b.x)return 1;
	return 0;
}

/* v1 and v2 is two vector */
inline int crossp(struct node v1,struct node v2)
{
	return v1.x*v2.y-v2.x*v1.y;
}

int isleft(int p1,int p2,int p3)
{
	return crossp(MAKE_VECTOR(p1,p2),MAKE_VECTOR(p2,p3));
}
/* compute convex hull via melkman algorithm */

void convex_hull()
{
	int i,t;
	bot=n-1; top=n; d[top++]=0; d[top++]=1;
	for (i=2;i<n;++i)
	{
		if (isleft(d[top-2],d[top-1],i)!=0) break;
		d[top-1]=i;
	}
	d[bot--]=i; d[top++]=i;
	if (isleft(d[n],d[n+1],d[n+2])<0)
	{
		t=d[n];
		d[n]=d[n+1];
		d[n+1]=t;
	}
	for (++i;i<n;++i)
	{
		if (isleft(d[bot+1],d[bot+2],i)>0 && isleft(d[top-2],d[top-1],i)>0) continue;
		while (isleft(d[top-2],d[top-1],i)<=0) --top;
		d[top++]=i;
		while (isleft(d[bot+1],d[bot+2],i)<=0) ++bot;
		d[bot--]=i;
	}
	for (i=bot+1;i<top;++i) h[i-bot-1]=d[i];
	np=top-bot-1;
}

double length(int p1,int p2)
{
	double dx,dy;
	dx=p[p2].x-p[p1].x;
	dy=p[p2].y-p[p1].y;
	return sqrt(dx*dx+dy*dy);
}

void solve()
{
	int i;
	double ans=0.0,per,cosalpha,pro;
	for (i=0;i<np-1;++i)
	{
		per=length(h[i],h[i+1]);
		ans+=per;
	}
	ans+=2*pi*L;
	printf("%d\n",(int)(ans+0.5));
}

int main()
{
	while (scanf("%d %d",&n,&L)!=EOF)
	{
		for (int i=0;i<n;++i) scanf("%d %d",&p[i].x,&p[i].y);
		sort(p,p+n,cmp);
		convex_hull();
		solve();
	}

	return 0;
}