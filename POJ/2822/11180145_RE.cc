#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#pragma comment(linker, "/STACK:32000000")
#define INF (1<<30)
#define N 100010
#define M 200010
int head[N],gap[N],dis[N],cur[N],cnt;
int n,m,s,t;
struct edge
{
    int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
    e[cnt].next=head[u]; e[cnt].v=v; e[cnt].w=w; head[u]=cnt++;
    e[cnt].next=head[v]; e[cnt].v=u; e[cnt].w=w; head[v]=cnt++;
}
int aug(int u,int m)
{
    if(u==t) return m;
    int flag=0,l=m,d;
    for(int i=cur[u];i!=-1;i=e[i].next)
    if(dis[e[i].v]+1==dis[u] && e[i].w>0)
    {
        d=aug(e[i].v,min(e[i].w,l));
        e[i].w-=d;
        e[i^1].w+=d;
        l-=d;
        if(e[i].w && ! flag)
        {
            flag=1;
            cur[u]=i;
        }
        if(dis[s]>=n || l==0) return m-l;
    }
    if(! flag)
    {
        int mindis=n;
        for(int i=head[u];i!=-1;i=e[i].next)
            if(e[i].w>0 && dis[e[i].v]<mindis)
            {
                mindis=dis[e[i].v];
                cur[u]=i;
            }
        if(--gap[dis[u]]==0) dis[s]=n;
        else ++gap[dis[u]=mindis+1];
    }
    return m-l;
}
queue<int> q;
void bfs()
{
    int i,u,v;
    memset(gap,0,sizeof(gap));
    memset(dis,-1,sizeof(dis));
    q.push(t);
    dis[t]=0;
    while (! q.empty())
    {
        u=q.front();
        q.pop();
        for(i=head[u];i!=-1;i=e[i].next)
        {
            v=e[i].v;
            if(dis[v]!=-1) continue;
            q.push(v);
            ++gap[dis[v]=dis[u]+1];
        }
    }
}
int sap()
{
    bfs();
    int ans=0;
    for(int i=1;i<=n;i++) cur[i]=head[i];
    while (dis[s]<n) ans+=aug(s,INF);
    return ans;
}
int main ()
{
    int tt,x,y,ml,mr;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%d%d",&n,&m);
        cnt=0;
        memset(head,-1,sizeof(head));
        s=t=1;
        scanf("%d%d",&x,&y);
        ml=mr=x;
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if(x<ml) ml=x,s=i;
            if(x>mr) mr=x,t=i;
        }
        while (m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        printf("%d\n",sap());
    }
    return 0;
}