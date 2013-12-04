#include<stdio.h>
#include<string.h>
#include <cmath>
#include <iostream>
using namespace std;
#define EPS 1e-8
#define INF 1e50
#define N 200
#define M 40010
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t,l;	int head[N],cur[N],cnt;
struct edge{    int v,next;double w;	}e[M];
int q[N],dis[N],start,end;
void addedge(int u,int v,double w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
int bfs()
{
    memset(dis,-1,sizeof(dis));    start=end=0; q[0]=t; dis[t]=0;
    while (start<=end)
    {
        int u=q[start++];
        for(int i=head[u];i!=-1;i=e[i].next)
        if(dis[e[i].v]==-1 && e[i^1].w>EPS){  dis[e[i].v]=dis[u]+1; q[++end]=e[i].v;  }
    }
    return dis[s]!=-1;
}
double dfs(int u,int t,double flow)
{
    if(u==t) return flow;    double delta=0;
    for(int &i=cur[u];i!=-1;i=e[i].next)
        if(dis[u]==dis[e[i].v]+1 && e[i].w>EPS)
        {
            double d=dfs(e[i].v,t,(((flow-delta)-e[i].w>EPS)?e[i].w:(flow-delta)));
            if(d<EPS) dis[e[i].v]=-1;
            e[i].w-=d;    e[i^1].w+=d;   delta+=d;
            if(fabs(delta-flow)<EPS) break;
        }
    return delta;
}
int main ()
{
	int tt,i;
	double a[N],b[N];
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d%d%d",&m,&n,&l);
		cnt=0;
		memset(head,-1,sizeof(head));
		s=n+m+1;
		t=m+n+2;
		for(i=1;i<=m;i++)
		{
			scanf("%lf",&a[i]);
			a[i]=log(a[i]);
			addedge(s,i,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&b[i]);
			b[i]=log(b[i]);
			addedge(i+m,t,b[i]);
		}
		while (l--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v+m,INF);
		}
		double ans=0;
		while (bfs()){	for(int i=1;i<=m+n+2;i++) cur[i]=head[i]; ans+=dfs(s,t,INF);}
		printf("%.4f\n",exp(ans));
	}
	
	return 0;
}