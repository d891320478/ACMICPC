#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
const int M=100010;
const int inf=1<<30;
int head[N];
struct Edge	{	 int v,next,w,l;	}edge[M];
int cnt,n,m,s,t,L;
int lft,rht,mid;
struct fff
{
	int ue,ve,we;
}e[M];
int cmp(const fff &a,const fff &b)
{
	return a.we<b.we;
}
void addedge(int u,int v,int w)
{
 edge[cnt].v=v;	 edge[cnt].w=w;	edge[cnt].next=head[u];
 head[u]=cnt++;
 edge[cnt].v=u;	 edge[cnt].w=0;	edge[cnt].next=head[v];
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
  if(flag) continue;
  int mindis=n;
  for(int j=head[u];j!=-1;j=edge[j].next)
  {
   int v=edge[j].v;
   if(edge[j].w>0&&dis[v]<mindis){ mindis=dis[v]; cur[u]=j; }
  }
  if((--gap[dis[u]])==0)   break;
  gap[dis[u]=mindis+1]++;  u=pre[u];
 }
 return flow;
}
int main()
{
    scanf("%d%d%d",&n,&m,&L);
    s=1,t=n;
    lft=1600000000;
    rht=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&e[i].ue,&e[i].ve,&e[i].we);
        rht=rht>e[i].we?rht:e[i].we;
        lft=lft<e[i].we?lft:e[i].we;
    }
    sort(e,e+m,cmp);
    while(lft<rht)
    {
    	mid=(lft+rht)/2;
    	cnt=0;
    	memset(head,-1,sizeof(head));
    	for(int i=0;i<m;i++)
    	{
    		if(e[i].we>mid)break;
    		addedge(e[i].ue,e[i].ve,1);
    		addedge(e[i].ve,e[i].ue,1);
    	}
    	int ans=sap();
    	if(ans>=L)rht=mid;
    	else lft=mid+1;
    }
    printf("%d\n",lft);

	return 0;
}