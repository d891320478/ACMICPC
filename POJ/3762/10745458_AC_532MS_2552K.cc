#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1<<30
#define SET(a,b) memset(a,b,sizeof(a))
#define N 5000
#define M 100000
int head[N],s,t,cnt,n,m,ans;
int d[N],pre[N];
bool vis[N];
int q[N];
struct edge
{
	int u,v,c,w,next;
}e[M];
void addedge(int u,int v,int w,int c)
{
	e[cnt].u=u; e[cnt].v=v; e[cnt].w=w; e[cnt].c=c; e[cnt].next=head[u]; head[u]=cnt++;
	e[cnt].u=v; e[cnt].v=u; e[cnt].w=-w; e[cnt].c=0; e[cnt].next=head[v]; head[v]=cnt++;
}
int SPFA(int n)
{
	int tail;
	SET(pre,-1); SET(vis,0);
	for(int i=0;i<n;i++) d[i]=-1;
	d[0]=0; tail=-1; q[++tail]=s; vis[s]=1;
	while (tail>=0)
	{
		int u=q[tail];
		tail--;
		vis[u]=0;
		for(int j=head[u];j!=-1;j=e[j].next)
		{
			int v=e[j].v;
			if(e[j].c>0 && d[u]+e[j].w>d[v])
			{
				d[v]=d[u]+e[j].w;
				pre[v]=j;
				if(! vis[v])
				{
					vis[v]=1;
					q[++tail]=v;
				}
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
		int u=t,mini=INF;
		while (u!=s)
		{
			if(e[pre[u]].c<mini) mini=e[pre[u]].c;
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

	int ha[M],sum=0,bh[87000],eu[M],ev[M],ew[M],k;
	char ch;
	scanf("%d%d%c",&m,&k,&ch);
	ha[0]=0;
	for(int i=1;i<=m;i++)
	{
		char s1[15],s2[15];
		scanf("%s %s %d",s1,s2,&ew[i]);
		int a,b=0;
		a=(s1[0]-'0')*10+s1[1]-'0';		b+=a*3600;
		a=(s1[3]-'0')*10+s1[4]-'0';		b+=a*60;
		a=(s1[6]-'0')*10+s1[7]-'0';		b+=a;
		eu[i]=b;
		ha[++ha[0]]=b;
		b=0;
		a=(s2[0]-'0')*10+s2[1]-'0';		b+=a*3600;
		a=(s2[3]-'0')*10+s2[4]-'0';		b+=a*60;
		a=(s2[6]-'0')*10+s2[7]-'0';		b+=a;
		ev[i]=b;
		ha[++ha[0]]=b;
	}
	sort(ha+1,ha+ha[0]+1);
	bh[ha[1]]=++sum;
	for(int i=2;i<=ha[0];i++)
		if(ha[i]!=ha[i-1]) bh[ha[i]]=++sum;
	s=0; t=sum+1;
	SET(head,-1); cnt=0;
	for(int i=1;i<=sum+1;i++) addedge(i-1,i,0,k);
	for(int i=1;i<=m;i++)
		addedge(bh[eu[i]],bh[ev[i]],ew[i],1);
	MCMF(sum+2);
	printf("%d\n",ans);
	
	return 0;
}