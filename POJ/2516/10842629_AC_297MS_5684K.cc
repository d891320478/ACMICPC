#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;
#define N 555
#define M 555555
#define INF 1<<30
struct edge
{
	int c,w,v,next;
}e[M];
int head[N],cnt;
int n,m,s,t,ans,flow;
int vis[N],d[N];
void addedge(int u,int v,int w,int c)
{
	e[cnt].next=head[u]; e[cnt].v=v; e[cnt].w=w; e[cnt].c=c; head[u]=cnt++;
	e[cnt].next=head[v]; e[cnt].v=u; e[cnt].w=0; e[cnt].c=-c; head[v]=cnt++;
}
int aug(int u,int f)
{
	if(u==t)
	{
		ans+=flow*f;
		return f;
	}
	vis[u]=1;
	int tmp=f;
	for(int i=head[u];i!=-1;i=e[i].next)
	if(e[i].w && ! e[i].c && ! vis[e[i].v])
	{
		int delta=aug(e[i].v,tmp<e[i].w?tmp:e[i].w);
		e[i].w-=delta;
		e[i^1].w+=delta;
		tmp-=delta;
		if(! tmp)return f;
	}
	return f-tmp;
}
bool modlabel(int n)
{
	for(int i=1;i<=n;i++) d[i]=INF;
	d[t]=0;
	deque<int> q;
	q.push_back(t);
	while(! q.empty())
	{
		int u=q.front();
		q.pop_front();
		for(int i=head[u];i!=-1;i=e[i].next)
			if(e[i^1].w && d[u]-e[i].c<d[e[i].v])
			{
				d[e[i].v]=d[u]-e[i].c;
				d[e[i].v]<=d[q.empty()?s:q.front()]?q.push_front(e[i].v):q.push_back(e[i].v);
			}
	}
	for(int u=1;u<=n;u++)
	for(int i=head[u];i!=-1;i=e[i].next)
		e[i].c+=d[e[i].v]-d[u];
	flow+=d[s];
	return d[s]<INF;
}
void costflow(int n)
{
	while (modlabel(n))
	{
		do{
			memset(vis,0,sizeof(vis));
		}while(aug(s,INF));
	}
}

int sum[N]={0},flag,a[N][N],b[N][N],f[N][N][N],k;

int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
    	if(n==0 && m==0 && k==0)break;
    	memset(sum,0,sizeof(sum));
    	for(int i=1;i<=n;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&a[i][j]);
    		sum[j]-=a[i][j];
    	}
    	for(int i=1;i<=m;i++)
    	for(int j=1;j<=k;j++)
    	{
    		scanf("%d",&b[i][j]);
    		sum[j]+=b[i][j];
    	}
    	for(int i=1;i<=k;i++)
    	for(int j=1;j<=n;j++)
    	for(int l=1;l<=m;l++) 
    		scanf("%d",&f[i][j][l]);
    	flag=1;
    	for(int i=1;i<=k;i++)
    		if(sum[i]<0){flag=0;break;}
    	if(!flag){printf("-1\n");continue;}
        s=1; t=m+n+2; ans=0;
        for(int z=1;z<=k;z++)
        {
        	cnt=0;
        	memset(head,-1,sizeof(head));
        	cnt=flow=0;
		    for(int i=1;i<=m;i++)
		    	addedge(s,i+1,b[i][z],0);
		    for(int i=1;i<=m;i++)
		    for(int j=m+1;j<=m+n;j++)
		    	addedge(i+1,j+1,INF,f[z][j-m][i]);
		    for(int i=m+1;i<=m+n;i++)
		    	addedge(i+1,t,a[i-m][z],0);
		    costflow(t);
		}
        printf("%d\n",ans);
    }
    return 0;
}