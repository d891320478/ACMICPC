#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=40000;
const int MAXE=20000000;
const int inf=1<<30;
int head[N],s,t,cnt,n,m,ans;
int d[N],pre[N];
bool vis[N];
int q[MAXE];
struct Edge
{
    int u,v,c,w,next;
}edge[MAXE];
void addedge(int u,int v,int w,int c)
{
    edge[cnt].u=u;    edge[cnt].v=v;    edge[cnt].w=w;    edge[cnt].c=c;
edge[cnt].next=head[u];    head[u]=cnt++;
    edge[cnt].v=u;    edge[cnt].u=v;    edge[cnt].w=-w;    edge[cnt].c=0;
    edge[cnt].next=head[v];    head[v]=cnt++;
}
int SPFA()
{
    int l,r;
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=t;i++) d[i]=inf;
    d[s]=0;
    l=0;r=0;
    q[r++]=s;
    vis[s]=1;
    while(l<r)
    {
        int u=q[l++];
        vis[u]=0;
        for(int j=head[u];j!=-1;j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].c>0&&d[u]+edge[j].w<d[v])
            {
                d[v]=d[u]+edge[j].w;
                pre[v]=j;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[r++]=v;
                }
            }
        }
    }
    if(d[t]==inf)        return 0;
    return 1;
}
void MCMF()
{
    int flow=0;
    while(SPFA())
    {
        int u=t;
        int mini=inf;
        while(u!=s)
        {
            if(edge[pre[u]].c<mini)
                mini=edge[pre[u]].c;
                u=edge[pre[u]].u;
        }
        flow+=mini;
        ans+=d[t]*mini;
        u=t;
        while(u!=s)
        {
            edge[pre[u]].c-=mini;
            edge[pre[u]^1].c+=mini;
            u=edge[pre[u]].u;
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s=0;t=n+1;cnt=0;
        for(int i=0;i<=t;i++)
            head[i]=-1;
        for(int i=1;i<=m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            addedge(u,v,cost,1);
            addedge(v,u,cost,1);
        }
        addedge(0,1,0,2);
        addedge(n,t,0,2);
        ans=0;
        MCMF();
        printf("%d\n",ans);
    }
    return 0;
}
