#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=20010;
const int M=500010;
const int inf=1<<30;
int head[N];
struct Edge	{	 int v,next,w;	}edge[M];
int cnt,n,m,s,t;
void addedge(int u,int v,int w)
{
 edge[cnt].v=v;	 edge[cnt].w=w;	 edge[cnt].next=head[u];
 head[u]=cnt++;
 edge[cnt].v=u;	 edge[cnt].w=0;	 edge[cnt].next=head[v];
 head[v]=cnt++;
}
int sap(int n)
{
 int pre[N],cur[N],dis[N],gap[N];
 int flow=0,aug=inf,u;
 bool flag;
 for(int i=1;i<=n;i++) {  cur[i]=head[i];  gap[i]=dis[i]=0;	 }
 gap[s]=n;	 u=pre[s]=s;
 while(dis[s]<n)
 {
  flag=0;
  for(int &j=cur[u];j!=-1;j=edge[j].next)
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
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    s=n+1;
    t=s+1;
    cnt=0;
    for(i=1;i<=n;i++)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	addedge(s,i,a);
    	addedge(i,t,b);
    }
    while (m--)
    {
    	int u,v,w;
    	scanf("%d%d%d",&u,&v,&w);
    	addedge(u,v,w);
    	addedge(v,u,w);
    }
    printf("%d\n",sap(n+2));
	return 0;
}