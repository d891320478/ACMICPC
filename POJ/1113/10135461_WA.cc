#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define N 1024
#define pi 3.141592653589793
#define MAKE_VECTOR(p1,p2) (struct node){P[p2].x-P[p1].x,P[p2].y-P[p1].y}
struct node
{
	int x,y;
}P[N];
int H[N],np;
int D[N*2],top,bot;
int n,L;

void input()
{
	for (int i=0;i<n;++i) scanf("%d %d",&P[i].x,&P[i].y);
}
/* v1 and v2 is two vector */

inline int crossP(struct node v1,struct node v2)
{
	return v1.x*v2.y-v2.x*v1.y;
}

int isleft(int p1,int p2,int p3)
{
	return crossP(MAKE_VECTOR(p1,p2),MAKE_VECTOR(p2,p3));
}
/* compute convex hull via melkman algorithm */

void convex_hull()
{
	int i,t;
	bot=n-1; top=n; D[top++]=0; D[top++]=1;
	for (i=2;i<n;++i)
	{
		if (isleft(D[top-2],D[top-1],i)!=0) break;
		D[top-1]=i;
	}
	D[bot--]=i; D[top++]=i;
	if (isleft(D[n],D[n+1],D[n+2])<0)
	{
		t=D[n];
		D[n]=D[n+1];
		D[n+1]=t;
	}
	for (++i;i<n;++i)
	{
		if (isleft(D[bot+1],D[bot+2],i)>0 && isleft(D[top-2],D[top-1],i)>0) continue;
		while (isleft(D[top-2],D[top-1],i)<=0) --top;
		D[top++]=i;
		while (isleft(D[bot+1],D[bot+2],i)<=0) ++bot;
		D[bot--]=i;
	}
	for (i=bot+1;i<top;++i) H[i-bot-1]=D[i];
	np=top-bot-1;
}

double length(int p1,int p2)
{
	double dx,dy;
	dx=P[p2].x-P[p1].x;
	dy=P[p2].y-P[p1].y;
	return sqrt(dx*dx+dy*dy);
}

void solve()
{
	int i;
	double ans=0.0,per,cosalpha,pro;
	for (i=0;i<np-1;++i)
	{
		per=length(H[i],H[i+1]);
		ans+=per;
	}
	ans+=2*pi*L;
	printf("%.0lf\n",nearbyint(ans));
}

int main()
{
	while (scanf("%d %d",&n,&L)==2)
	{
		input();
		convex_hull();
		solve();
	}

	return 0;
}