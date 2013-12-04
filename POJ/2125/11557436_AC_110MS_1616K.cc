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
#define INF (1<<30)
#define N 101000
#define M 500010
#pragma comment(linker, "/STACK:32000000")
int n,m,s,t;	int head[N],cur[N],cnt;
struct edge{    int v,w,next;	}e[M];
int q[N],dis[N],start,end;
void addedge(int u,int v,int w)
{	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
int bfs()
{
    memset(dis,-1,sizeof(dis));    start=end=0; q[0]=t; dis[t]=0;
    while (start<=end)
    {
        int u=q[start++];
        for(int i=head[u];i!=-1;i=e[i].next)
        if(dis[e[i].v]==-1 && e[i^1].w>0){  dis[e[i].v]=dis[u]+1; q[++end]=e[i].v;  }
    }
    return dis[s]!=-1;
}
int dfs(int u,int t,int flow)
{
    if(u==t) return flow;    int delta=flow;
    for(int &i=cur[u];i!=-1;i=e[i].next)
        if(dis[u]==dis[e[i].v]+1 && e[i].w>0)
        {
            int d=dfs(e[i].v,t,min(delta,e[i].w));
            e[i].w-=d;    e[i^1].w+=d;   delta-=d;
            if(delta==0) break;
        }
    return flow-delta;
}
bool vis[N];
struct ad
{
	int x;
	char y;
}ais[N];
void dfs(int s)
{
	vis[s]=1;
	for(int i=head[s];i!=-1;i=e[i].next)
		if(e[i].w>0 && ! vis[e[i].v]) dfs(e[i].v);
}
int main()
{
	int i,j,w,u,v;
	scanf("%d%d",&n,&m);
	s=2*n+1,t=s+1;
	cnt=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(i+n,t,w);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&w);
		addedge(s,i,w);
	}
	while (m--)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v+n,INF);
	}
	int ans=0;
	while (bfs())
	{
		for(int i=1;i<=t;i++)
			cur[i]=head[i];
		ans+=dfs(s,t,INF);
	}
	printf("%d\n",ans);
	dfs(s);
	int diy=0;
	for(j=head[s];j!=-1;j=e[j].next)
		if(! vis[e[j].v])
		{
			diy++;
			ais[diy].x=e[j].v;
			ais[diy].y='-';
		}
	for(i=n+1;i<s;i++)
		if(vis[i])
		{
			diy++;
			ais[diy].x=i-n;
			ais[diy].y='+';
		}
	printf("%d\n",diy);
	for(i=1;i<=diy;i++)
		printf("%d %c\n",ais[i].x,ais[i].y);
		
	return 0;
}