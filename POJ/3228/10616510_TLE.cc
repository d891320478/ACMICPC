#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=210;
const int M=100010;
const int inf=1<<30;
int head[N];
struct Edge	{	 int v,next,w;	}edge[M];
int cnt,n,m,s,t;
struct ee
{
	int u,v,w;
}e[M];
int cmp(const ee &a,const ee &b)
{
	return a.w<b.w;
}
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
 gap[0]=n;
 u=pre[s]=s;
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
     while(u!=s){     u=pre[u];      edge[cur[u]].w-=aug;      edge[cur[u]^1].w+=aug;     }
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
   if(edge[j].w>0&&dis[v]<mindis){      mindis=dis[v];              cur[u]=j;            }
  }
  if((--gap[dis[u]])==0)   break;
  gap[dis[u]=mindis+1]++;  u=pre[u];
 }
 return flow;
}
int a[N],b[N],g[N][N],l[M],ll;
int lft,rht,mid,su,ma;
int main()
{
    int i,j;
    while(scanf("%d",&n) && n)
    {
		s=n+1;
		t=s+1;
		ma=su=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			su+=a[i];
		}
		for(i=1;i<=n;i++)
			scanf("%d",&b[i]);
		memset(g,-1,sizeof(g));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
			l[i]=e[i].w;
		}
		sort(l,l+m);
		ll=0;
		for(i=1;i<m;i++)
			if(l[i]!=l[i-1])l[++ll]=l[i];
		lft=0; rht=ll;
		int ans=-1;
		while(lft<=rht)
		{
			memset(head,-1,sizeof(head));
			cnt=0;
			mid=(lft+rht)>>1;
			for(i=1;i<=n;i++)
			{
				if(a[i]>0)addedge(s,i,a[i]);
				if(b[i]>0)addedge(i,t,b[i]);
			}
			for(i=0;i<m;i++)
			if(e[i].w<=l[mid])
			{
				addedge(e[i].u,e[i].v,inf);
				addedge(e[i].v,e[i].u,inf);
			}
			if(sap(n+2)>=su)rht=mid-1,ans=l[mid];
			else lft=mid+1;
		}
		if(ans==-1) printf("No Solution\n");
		else printf("%d\n",ans);
	}
	return 0;
}