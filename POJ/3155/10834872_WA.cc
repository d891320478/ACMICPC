#include<stdio.h>
#include<string.h>
#include <cmath>
#define EPS 1e-4
const int N=10010;
const int M=20010;
#define inf 1e20
struct Edge
{    int v,next; double w;	}e[M];
int head[N],cnt;	int n,m,ans;	int s,t;	int pre[N],cur[N],dis[N],gap[N];
int q[N],open,tail;
void addedge(int u,int v,double w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];    head[v]=cnt++;
}
/*void BFS()
{
	int i,u,v;
	memset(gap,0,sizeof(gap));
	memset(dis,-1,sizeof(dis));
	open=tail=0;
	q[open]=t;
	dis[t]=0;
	while (open<=tail)
	{
		u=q[open++];
		for(i=head[u];i!=-1;i=e[i].next)
		{
			v=e[i].v;
			if(e[i].w!=0 || dis[v]!=-1) continue;
			q[++tail]=v;
			++gap[dis[v]=dis[u]+1];
		}
	}
}*/
double sap(int n)
{
    int i,v,u;
    double flow=0,aug=inf;
    int flag;
    //BFS();
    gap[s]=2;
    gap[t]=0;
    for (i=1;i<=n;i++) {cur[i]=head[i];if(i<s)gap[i]=1;}
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
                    aug=inf;
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
            if (e[j].w>0&&mindis>dis[v])
		   {   mindis=dis[v];    cur[u]=j;	}
        }
        if (--gap[dis[u]]==0) break;
	    ++gap[dis[u]=mindis+1];     u=pre[u];
    }
   return flow;
}
int u[N],v[N],vis[N+M];
void dfs(int s)
{
	vis[s]=1;
	for(int i=head[s];i!=-1;i=e[i].next)
		if(e[i].w>0 && ! vis[e[i].v]) dfs(e[i].v);
}
int main ()
{
	int i;
	while (scanf("%d%d",&n,&m)!=-1)
	{
		if(m==0)
		{
			printf("1\n1\n");
			continue;
		}
		for(i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
		s=n+m+1;
		t=s+1;
		double l=0,r=m,mid;
		while (fabs(r-l)>EPS)
		{
			mid=(l+r)/2;
			cnt=0;
			memset(head,-1,sizeof(head));
			for(i=1;i<=m;i++)
			{
				addedge(s,i,1);
				addedge(i,u[i]+m,inf);
				addedge(i,v[i]+m,inf);
			}
			for(i=1;i<=n;i++)
				addedge(i+m,t,mid);
			double ans=(double)m-sap(t);
			if(ans==0) r=mid;
			else l=mid;
		}
		/*for(i=1;i<=t;i++)
		{
			for(int j=head[i];j!=-1;j=e[j].next)
				printf("%d %.2lf  ",e[j].v,e[j].w);
			printf("\n");
		}
		printf("\n");
		cnt=0;
		memset(head,-1,sizeof(head));
		for(i=1;i<=m;i++)
		{
			addedge(s,i,1);
			addedge(i,u[i]+m,inf);
			addedge(i,v[i]+m,inf);
		}
		for(i=1;i<=n;i++)
			addedge(i+m,t,l);
		sap(t);
		for(i=1;i<=t;i++)
		{
			for(int j=head[i];j!=-1;j=e[j].next)
				printf("%d %.2lf  ",e[j].v,e[j].w);
			printf("\n");
		}
		printf("\n");*/
		memset(vis,0,sizeof(vis));
		dfs(s);
		int ans=0;
		for(i=m+1;i<=m+n;i++)
			if(vis[i]) ans++;
		printf("%d\n",ans);
		for(i=m+1;i<=m+n;i++)
			if(vis[i]) printf("%d\n",i-m);
	}
	
	return 0;
}