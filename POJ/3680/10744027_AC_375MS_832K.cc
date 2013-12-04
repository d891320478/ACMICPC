#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 500
#define M 1000
#define INF 1<<30
int head[N],s,t,cnt,n,m,ans;
int d[N],pre[N],u[N],v[N],w[N];
bool vis[N];
int q[M];
int qp[N*M],bh[100010];
struct Edge
{
	int u,v,w,c,next;
}e[M];
void addedge(int u,int v,int w,int c)
{
	e[cnt].u=u; e[cnt].v=v; e[cnt].w=w; e[cnt].c=c;
	e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].u=v; e[cnt].v=u; e[cnt].w=-w; e[cnt].c=0;
	e[cnt].next=head[v]; head[v]=cnt++;
}
int SPFA(int n)
{
	int l,r;
	memset(pre,-1,sizeof(pre));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) d[i]=-1;
	d[s]=l=r=0;
	q[r++]=s;
	vis[s]=1;
	while (l<r)
	{
		int u=q[l++]; vis[u]=0;
		for(int j=head[u];j!=-1;j=e[j].next)
		{
			int v=e[j].v;
			if(e[j].c>0 && d[u]+e[j].w>d[v])
			{
				d[v]=d[u]+e[j].w;
				pre[v]=j;
				if(! vis[v]) vis[v]=1,q[r++]=v;
			}
		}
	}
	if(d[t]==-1)return 0;
	return 1;
}
void MCMF(int n)
{
	int flow=0;
	while (SPFA(n))
	{
		int u=t;
		int mini=INF;
		while (u!=s)
		{
			if(e[pre[u]].c<mini)mini=e[pre[u]].c;
			u=e[pre[u]].u;
		}
		flow+=mini;
		ans+=d[t]*mini;
		u=t;
		while (u!=s)
		{
			e[pre[u]].c-=mini;
			e[pre[u]^1].c+=mini;
			u=e[pre[u]].u;
		}
	}
}
int main ()
{
	int m,i,k,sum,tttt,bb;
	scanf("%d",&tttt);
	while(tttt--)
	{
		scanf("%d%d",&m,&k);
		qp[0]=-1;sum=bb=1;
		memset(head,-1,sizeof(head));
		cnt=0;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
			qp[sum++]=u[i];
			qp[sum++]=v[i];
		}
		sort(qp,qp+sum);
		for(i=1;i<sum;i++)
			if(qp[i]!=qp[i-1])bh[qp[i]]=bb++;
		s=0;
		t=bb;
		for(i=0;i<bb;i++)
			addedge(i,i+1,0,k);
		for(i=1;i<=m;i++)
			addedge(bh[u[i]],bh[v[i]],w[i],1);
		ans=0;
		MCMF(bb+1);
		printf("%d\n",ans);
	}
		
	return 0;
}