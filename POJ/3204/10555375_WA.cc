#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=510;
const int M=10010;
const int inf=1<<30;
int head[N];
struct Edge	{	 int u,v,next,w;	}edge[M];
int cnt,n,m,s,t;
int ans,a[N][N];
int vs[N],vt[N];
void addedge(int u,int v,int w)
{
 edge[cnt].u=u; edge[cnt].v=v;	 edge[cnt].w=w;	 edge[cnt].next=head[u];
 head[u]=cnt++;
 edge[cnt].u=v; edge[cnt].v=u;	 edge[cnt].w=0;	 edge[cnt].next=head[v];
 head[v]=cnt++;
}
int sap()
{
 int pre[N],cur[N],dis[N],gap[N];	 int flow=0,aug=inf,u;	 bool flag;
 for(int i=1;i<=n;i++) {  cur[i]=head[i];  gap[i]=dis[i]=0;	 }
 gap[s]=n;	 u=pre[s]=s;
 while(dis[s]<n)
 {
  flag=0;
  for(int j=cur[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[u]==dis[v]+1)
   {
    flag=1;    if(edge[j].w<aug) aug=edge[j].w;
    pre[v]=u;    u=v;
    if(u==t)
    {
     flow+=aug;
     while(u!=s)     {      u=pre[u];      edge[cur[u]].w-=aug;      edge[cur[u]^1].w+=aug;     }
     aug=inf;
    }
     break;
   }
  }
  if(flag)   continue;
  int mindis=n;
  for(int j=head[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[v]<mindis)            {              mindis=dis[v];              cur[u]=j;            }
  }
  if((--gap[dis[u]])==0)   break;
  gap[dis[u]=mindis+1]++;  u=pre[u];
 }
 return flow;
}
bool dfs(int s,int* vis)
{
	vis[s]=1;
	for(int i=1;i<=n;i++)
		if(a[s][i] && ! vis[i])
			dfs(i,vis);
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    s=1,t=n;
    cnt=0;
    for(int i=1;i<=m;i++)
    {
    	int ue,ve,we;
        scanf("%d%d%d",&ue,&ve,&we);
        addedge(ue+1,ve+1,we);
    }
    sap();
    for(int i=0;i<cnt;i+=2)
    	if(edge[i].w>0)a[edge[i].u][edge[i].v]=1;
    ans=0;
    dfs(1,vs);
    memset(a,0,sizeof(a));
    for(int i=0;i<cnt;i+=2)
    	if(edge[i].w>0)a[edge[i].v][edge[i].u]=1;
    dfs(n,vt);
    for(int i=0;i<cnt;i+=2)
    	if(vs[edge[i].u] && vt[edge[i].v] && edge[i].w<=0)ans++;
    printf("%d\n",ans);
	return 0;
}