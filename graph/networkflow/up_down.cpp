//无源汇上下界可行流
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define INF (1<<30)
#define N 210
#define M 80010
int head[N],gap[N],dis[N],cur[N],cnt;
int n,m,s,t;
struct edge
{
	int v,w,next;
}e[M];
void addedge(int u,int v,int w)
{
	e[cnt].v=v; e[cnt].w=w; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].v=u; e[cnt].w=0; e[cnt].next=head[v]; head[v]=cnt++;
}
int aug(int u,int m)
{
	if(u==t) return m;
	int flag=0,l=m,d;
	for(int i=cur[u];i!=-1;i=e[i].next)
	if(dis[e[i].v]+1==dis[u] && e[i].w>0)
	{
		d=aug(e[i].v,min(l,e[i].w));
		e[i].w-=d; e[i^1].w+=d; l-=d;
		if(! flag)
		{
			flag=1;
			cur[u]=i;
		}
		if(dis[s]>=n || l==0) return m-l;
	}
	if(! flag)
	{
		int mindis=n;
		for(int i=head[u];i!=-1;i=e[i].next)
		if(e[i].w>0 && dis[e[i].v]<mindis)
		{
			mindis=dis[e[i].v];
			cur[u]=i;
		}
		if(--gap[dis[u]]==0) dis[s]=n;
		else ++gap[dis[u]=mindis+1];
	}
	return m-l;
}
int sap()
{
	memset(gap,0,sizeof(gap));
	memset(dis,0,sizeof(dis));
	gap[0]=n;
	int ans=0;
	for(int i=1;i<=n;i++)
		cur[i]=head[i];
	while(dis[s]<n) ans+=aug(s,INF);
	return ans;
}
int bi[N],bo[N],w1[M],w2[M];
int main()
{
		scanf("%d%d",&n,&m);
		s=n+1;
		t=n+2;
		n+=2;
		cnt=0;
		memset(head,-1,sizeof(head));
		memset(bi,0,sizeof(bi));
		memset(bo,0,sizeof(bo));
		for(int i=0;i<m;i++)
		{
			int u,v;
			scanf("%d%d%d%d",&u,&v,&w1[i],&w2[i]);
			addedge(u,v,w2[i]-w1[i]);
			bi[v]+=w1[i];
			bo[u]+=w1[i];
		}
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++)
		{
			if(bi[i]-bo[i]>0) addedge(s,i,bi[i]-bo[i]),sum1+=bi[i]-bo[i];
			if(bi[i]-bo[i]<0) addedge(i,t,bo[i]-bi[i]),sum2+=bo[i]-bi[i];
		}
		if(sap()==sum1)
		{
			printf("YES\n");
			for(int i=0;i<m;i++)
				printf("%d\n",e[i*2+1].w+w1[i]);
		}
		else printf("NO\n");
	return 0;
}
