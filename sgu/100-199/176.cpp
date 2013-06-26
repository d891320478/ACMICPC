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
int u[M],v[M];
int main()
{
freopen("1.in","r",stdin);
		scanf("%d%d",&n,&m);
		s=n+1;
		t=n+2;
		n+=2;
		memset(bi,0,sizeof(bi));
		memset(bo,0,sizeof(bo));
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&u[i],&v[i],&w2[i],&w1[i]);
			if(w1[i]==1) w1[i]=w2[i];
			bi[v[i]]+=w1[i];
			bo[u[i]]+=w1[i];
		}
		int l=0,r=INF,mid;
		while (l<r)
		{
			mid=(l+r)>>1;
			cnt=0;
			memset(head,-1,sizeof(head));
			for(int i=0;i<m;i++) addedge(u[i],v[i],w2[i]-w1[i]);
			addedge(n-2,1,mid);
			int sum=0;
			for(int i=1;i<=n;i++)
			{
				if(bi[i]-bo[i]>0) addedge(s,i,bi[i]-bo[i]),sum+=bi[i]-bo[i];
				if(bi[i]-bo[i]<0) addedge(i,t,bo[i]-bi[i]);
			}
			int ans=sap();
			if(ans==sum) r=mid;
			else l=mid+1;
		}
		if(l==INF) printf("Impossible\n");
		else
		{
			cnt=0;
			memset(head,-1,sizeof(head));
			for(int i=0;i<m;i++) addedge(u[i],v[i],w2[i]-w1[i]);
			addedge(n-2,1,l);
			for(int i=1;i<=n;i++)
			{
				if(bi[i]-bo[i]>0) addedge(s,i,bi[i]-bo[i]);
				if(bi[i]-bo[i]<0) addedge(i,t,bo[i]-bi[i]);
			}
			sap();
			printf("%d\n",l);
			for(int i=0;i<m;i++)
			{
				printf("%d",e[i<<1|1].w+w1[i]);
				if(i<m-1) printf(" ");
				else printf("\n");
			}
		}
	return 0;
}
