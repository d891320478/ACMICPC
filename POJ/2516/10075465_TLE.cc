#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=60;
const int MAXE=10000;
const int inf=1<<30;
int head[N],s,t,cnt,n,m,ans,k,saber;
int d[N],pre[N];
bool vis[N];
int q[MAXE];
struct Edge
{
    int u,v,c,w,next;
}edge[MAXE];
void addedge(int u,int v,int w,int c)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].c=c;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].u=v;
    edge[cnt].w=-w;
    edge[cnt].c=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
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
    if(d[t]==inf)
        return 0;
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
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
    	if(n==0 && m==0 && k==0)break;
    	int sum[N]={0},flag=1,a[N][N],b[N][N],c[N][N][N];
    	for(int i=1;i<=n;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&a[i][j]);
    		sum[j]-=a[i][j];
    	}
    	for(int i=1;i<=m;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&b[i][j]);
    		sum[j]+=b[i][j];
    	}
    	for(int i=1;i<=k;i++)
    	for(int j=1;j<=n;j++)
    	for(int l=1;l<=m;l++) 
    		scanf("%d",&c[i][j][l]);
    	for(int i=1;i<=k;i++)
    		if(sum[i]<0){flag=0;break;}
    	if(!flag){printf("-1\n");continue;}
        s=0;t=m+n+1;saber=0;
        for(int z=1;z<=k;z++)
        {
        	cnt=0;
		    for(int i=0;i<=t;i++)
		        head[i]=-1;
		    for(int i=1;i<=m;i++)
		    	addedge(0,i,0,100000);
		    for(int i=1;i<=m;i++)
		    for(int j=m+1;j<=m+n;j++)
		    	addedge(i,j,c[z][j-m][i],b[i][z]);
		    for(int i=m+1;i<=m+n;i++)
		    	addedge(i,t,0,a[i-m][z]);
		    ans=0;
		    MCMF();
		    saber+=ans;
		}
        printf("%d\n",saber);
    }
    return 0;
}