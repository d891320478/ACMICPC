#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=6000;
const int MAXE=200000;
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
    for(int i=0;i<=t;i++) d[i]=-1;
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
            if(edge[j].c>0 && d[u]+edge[j].w>d[v])
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
    if(d[t]==-1) return 0;
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
int k;
int a[60][60];
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        s=0; t=n*n*2+1;
        cnt=0;
        for(int i=0;i<=t;i++)
            head[i]=-1;
        addedge(s,1,0,k);
        addedge(n*n*2,t,0,k);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        	scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
        	int x=(i-1)*n+j;
        	addedge(x,x+n*n,a[i][j],1);
        	addedge(x,x+n*n,0,1000000);
        	if(i+1<=n)
        		addedge(x+n*n,x+n,0,1000000);
        	if(j+1<=n)
        		addedge(x+n*n,x+1,0,1000000);
        }
        ans=0;
        MCMF();
        printf("%d\n",ans);
    }
    return 0;
}