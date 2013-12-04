#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1510
#define M 2250010
#define INF (1<<30)
int n,m,s,t,ans;
int head[N],cnt,dis[N];
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt]=(edge){v,w,head[u]}; head[u]=cnt++;
	e[cnt]=(edge){u,0,head[v]}; head[v]=cnt++;
}
int bfs()
{
	queue<int> q;
	while (! q.empty()) q.pop();
	memset(dis,0,sizeof(dis));
	dis[s]=1; q.push(s);
	while (! q.empty())
	{
		int u=q.front(),v;
		q.pop();
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i].w && dis[v=e[i].v]==0)
			{
				dis[v]=dis[u]+1;
				if(v==t) return 1;
				q.push(v);
			}
	}
	return 0;
}
int dfs(int s,int limit)
{
	if(s==t) return limit;
	int v,tmp,cost=0;
	for(int i=head[s];i!=-1;i=e[i].next)
	if(e[i].w && dis[s]==dis[v=e[i].v]-1)
	{
		tmp=dfs(v,min(limit-cost,e[i].w));
		if(tmp>0)
		{
			e[i].w-=tmp;
			e[i^1].w+=tmp;
			cost+=tmp;
			if(limit==cost) break;
		}else dis[v]=-1;
	}
	return cost;
}
int main()
{
	int m,f,d,i,j,k,l,c;
    while(scanf("%d%d%d",&m,&f,&d)!=-1)
    {
        memset(head,-1,sizeof(head));
        s=1; t=n=2*m+f+d+2; cnt=0;
        for(i=2;i<=f+1;i++)
        	addedge(s,i,1);
        for(i=f+2*m+2;i<t;i++)
        	addedge(i,t,1);
        for(i=f+2;i<=f+m+1;i++)
        	addedge(i,i+m,1);
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&k,&l);
            for(j=1;j<=k;j++)
            {
            	int ue;
            	scanf("%d",&ue);
            	addedge(ue+1,f+1+i,1);
            }
            for(j=1;j<=l;j++)
            {
            	int ue;
            	scanf("%d",&ue);
            	addedge(f+m+1+i,ue+2*m+f+1,1);
            }
        }
        ans=0;
        while(bfs()) ans+=dfs(s,INF);
        printf("%d\n",ans);
    }
    return 0;
}