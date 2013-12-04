#include<stdio.h>
#include<string.h>
#include <cmath>
#define EPS 1e-8
const int N=200;
const int M=40000;
#define INF 1e50
struct Edge
{    int v,next;
	double w;	}e[M];
int head[N],cnt;	int n,m,l;	int s,t;	int pre[N],cur[N],dis[N],gap[N];
void addedge(int u,int v,double w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
double sap(int n)
{
    int i,v,u;
    double flow=0,aug=INF;
    int flag;
    for (i=1;i<=n;i++)
    {   gap[i]=dis[i]=0;       cur[i]=head[i];    }
    gap[0]=n; //gap[s]=n;
    u=pre[s]=s;
	while (dis[s]<n)
	{   flag=0;
        for (int j=cur[u];j!=-1;j=e[j].next)
	 {   v=e[j].v;
            if (e[j].w>0&&dis[u]==dis[v]+1)
		   {
                flag=1;    if (e[j].w<aug) aug=e[j].w;     pre[v]=u;      u=v;
                if (u==t)
			   {
                    flow+=aug;
                    while (u!=s)
				   {  u=pre[u];   e[cur[u]].w-=aug;    e[cur[u]^1].w+=aug;    }
                    aug=INF;
                }
                break;
            }
            cur[u]=e[j].next;
        }
        if (flag) continue;
        int mindis=n;
        for (int j=head[u];j!=-1;j=e[j].next)
	 {
            v=e[j].v;
            if (e[j].w>EPS && mindis>dis[v])
		   {   mindis=dis[v];    cur[u]=j;	}
        }
        if (--gap[dis[u]]==0) break;
        dis[u]=mindis+1;   ++gap[dis[u]];     u=pre[u];
    }
   return flow;
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
		double ans=sap(n+m+2);
		printf("%.4f\n",exp(ans));
	}
	
	return 0;
}