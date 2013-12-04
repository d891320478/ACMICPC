#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=40000;
const int M=20000000;
const int inf=1<<30;
int head[N],s,t,cnt,n,m,ans,kk;
int d[N],pre[N];
bool vis[N];
int q[M];
struct Edge
{   int u,v,c,w,next;	}edge[M];
void addedge(int u,int v,int w,int c)
{
    edge[cnt].u=u;    edge[cnt].v=v;    edge[cnt].w=w;    edge[cnt].c=c;
	edge[cnt].next=head[u];    head[u]=cnt++;
    edge[cnt].v=u;    edge[cnt].u=v;    edge[cnt].w=-w;    edge[cnt].c=0;
    edge[cnt].next=head[v];    head[v]=cnt++;
}
int SPFA(int n)
{
    int l,r;
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=l=r=0;    q[r++]=s;    vis[s]=1;
    while(l<r)
    {
        int u=q[l++];        vis[u]=0;
        for(int j=head[u];j!=-1;j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].c>0&&d[u]+edge[j].w<d[v])
            {
                d[v]=d[u]+edge[j].w;      pre[v]=j;
                if(!vis[v])
                {    vis[v]=1;     q[r++]=v;      }
            }
        }
    }
    if(d[t]==inf)  return 0;
    return 1;
}
void MCMF(int n)
{
    int flow=0;
    while(SPFA(n))
    {
        int u=t;
        if(d[t]>kk) break;
        ans++;
        while(u!=s)
        { edge[pre[u]].c-=1;    edge[pre[u]^1].c+=1;    u=edge[pre[u]].u;     }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&kk)!=EOF)
    {
    	if(!(n+m+kk))break;
        cnt=0;
        for(int i=1;i<=2*n;i++) head[i]=-1;
        s=n+1; t=n;
        for(int i=1;i<=n;i++)
        	addedge(i,i+n,0,1);
        while (m--)
        {
        	int u,v;
        	scanf("%d%d",&u,&v);
        	addedge(u+n,v,1,inf);
        }
        ans=0;
        MCMF(2*n);
        printf("%d\n",ans);
    }
    return 0;
}