#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=401;
const int M=1000001;
const int inf=1<<30;
int head[N];
struct Edge
{
 int v,next,w;
}edge[M];
int cnt,n,m,s,t;
int a[N],g[N][N],u[N];
void addedge(int u,int v,int w)
{
 edge[cnt].v=v;
 edge[cnt].w=w;
 edge[cnt].next=head[u];
 head[u]=cnt++;
 edge[cnt].v=u;
 edge[cnt].w=0;
 edge[cnt].next=head[v];
 head[v]=cnt++;
}
int sap()
{
 int pre[N],cur[N],dis[N],gap[N];
 int flow=0,aug=inf,u;
 bool flag;
 for(int i=1;i<=2*n;i++)
 {
  cur[i]=head[i];
  gap[i]=dis[i]=0;
 }
 gap[s]=2*n;
 u=pre[s]=s;
 while(dis[s]<2*n)
 {
  flag=0;
  for(int &j=cur[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[u]==dis[v]+1)
   {
    flag=1;
    if(edge[j].w<aug) aug=edge[j].w;
    pre[v]=u;
    u=v;
    if(u==t)
    {
     flow+=aug;
     while(u!=s)
     {
      u=pre[u];
      edge[cur[u]].w-=aug;
      edge[cur[u]^1].w+=aug;
     }
     aug=inf;
    }
                break;
   }
  }
  if(flag)
   continue;
  int mindis=2*n;
  for(int j=head[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[v]<mindis)
            {
              mindis=dis[v];
              cur[u]=j;
            }
  }
  if((--gap[dis[u]])==0)
   break;
  gap[dis[u]=mindis+1]++;
  u=pre[u];
 }
 return flow;
}
 
int main()
{
	int i,j;
	memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++) scanf("%d",&a[i]);
    s=n+1; t=n+2;
    for(i=1;i<=n;i++)
    {
    	int value;
    	scanf("%d",&g[i][0]);
    	for(j=1;j<=g[i][0];j++) scanf("%d",&g[i][j]);
    	scanf("%d",&value);
    	addedge(i,t,value);
    }
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=g[i][0];j++)
    	{
    		if(! u[g[i][j]])
    		{
    			u[g[i][j]]=i;
    			addedge(s,i,a[g[i][j]]);
    		}
    		else
    		{
    			addedge(u[g[i][j]],i,100000000);
    			u[g[i][j]]=i;
    		}
    	}
    }
    printf("%d\n",sap());
    
    return 0;
}