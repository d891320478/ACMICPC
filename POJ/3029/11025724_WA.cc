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
#define EPS 1e-10
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
int a[10],vis[10],n;
double v0;
double ans0;
struct people
{
	double x,y,v,a;
	void init(){scanf("%lf%lf%lf%lf",&x,&y,&v,&a);}
}p[10];
void check()
{
	double xx=0,yy=0,t,t0=0,ans=0,t1,t2;
	double x[10],y[10];
	for(int i=1;i<=n;i++)
	{
		x[i]=p[i].x;
		y[i]=p[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		int now=a[i];
		double xs=x[now]-xx,ys=y[now]-yy;
		double ffff=p[now].v*(xs*cos(p[now].a)+ys*sin(p[now].a));
		t1=(-2*ffff+sqrt(4*ffff*ffff-4*(xs*xs+ys*ys)*(p[now].v*p[now].v-v0*v0)))/(2*(p[now].v*p[now].v-v0*v0));
		t2=(-2*ffff-sqrt(4*ffff*ffff-4*(xs*xs+ys*ys)*(p[now].v*p[now].v-v0*v0)))/(2*(p[now].v*p[now].v-v0*v0));
		if(t1>-EPS && t2>-EPS) t=min(t1,t2);
		else if(fabs(t1)<EPS || fabs(t2)<EPS) t=0;
		else if(t1>-EPS) t=t1;
		else t=t2;
		xx=x[now]+p[now].v*cos(p[now].a)*t;
		yy=y[now]+p[now].v*sin(p[now].a)*t;
		t0+=t;
		for(int j=i+1;j<=n;j++)
		{
			x[a[j]]+=p[a[j]].v*cos(p[a[j]].a);
			y[a[j]]+=p[a[j]].v*sin(p[a[j]].a);
		}
		if(ans<t0+sqrt(xx*xx+yy*yy)/p[now].v) ans=t0+sqrt(xx*xx+yy*yy)/p[now].v;
	}
	if(ans0>ans) ans0=ans;
}
void dfs(int step)
{
	if(step>n)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
		if(! vis[i])
		{
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
}
int main ()
{
	while (scanf("%d",&n) && n)
	{
		scanf("%lf",&v0);
		for(int i=1;i<=n;i++) p[i].init();
		ans0=1e50;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		dfs(1);
		printf("%.0f\n",ans0);
	}
	
	return 0;
}