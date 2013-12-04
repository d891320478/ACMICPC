#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define N 40
#define M 2000
#define INF (1<<20)
struct Edge
{
	int v,next,w;
}e[M];
int head[N],cnt,n,m,ans;
int s,t;
int pre[N],cur[N],dis[N],gap[N];
void addedge(int u,int v,int w)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u];
	head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=0; e[cnt].next=head[v];
	head[v]=cnt++;
}
int sap(int n)
{
	int i,v,u,flow=0,aug=INF;
	int flag;
	for(i=1;i<=n;i++)
	{
		gap[i]=dis[i]=0;
		cur[i]=head[i];
	}
	gap[0]=n;
	u=pre[s]=s;
	while(dis[s]<n)
	{
		flag=0;
		for(int j=cur[u];j!=-1;j=e[j].next)
		{
			v=e[j].v;
			if(e[j].w>0 && dis[u]==dis[v]+1)
			{
				flag=1;
				if(e[j].w<aug)aug=e[j].w;
				pre[v]=u;
				u=v;
				if(u==t)
				{
					flow+=aug;
					while (u!=s)
					{
						u=pre[u];
						e[cur[u]].w-=aug;
						e[cur[u]^1].w+=aug;
					}
					aug=INF;
				}
				break;
			}
			cur[u]=e[j].next;
		}
		if(flag)continue;
		int mindis=n;
		for(int j=head[u];j!=-1;j=e[j].next)
		{
			v=e[j].v;
			if(e[j].w>0 && mindis>dis[v])
			{
				mindis=dis[v];
				cur[u]=j;
			}
		}
		if(--gap[dis[u]]==0)break;
		dis[u]=mindis+1;
		++gap[dis[u]];
		u=pre[u];
	}
	return flow;
}
int main ()
{
	int tt,i,j,k;
	string ss;
	scanf("%d",&tt);
	while (tt--)
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		scanf("%d%d",&n,&t);
		t++;
		s=n+1;
		for(i=1;i<=n;i++)
		{
			cin>>ss;
			if(ss=="I") addedge(s,i,INF);
			scanf("%d",&j);
			while (j--)
			{
				scanf("%d",&k);
				k++;
				addedge(i,k,INF);
				addedge(k,i,1);
			}
		}
		ans=sap(n+1);
		if(ans>=INF)puts("PANIC ROOM BREACH");
		else printf("%d\n",ans);
	}
	
	return 0;
}