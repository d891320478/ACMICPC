#include<stdio.h>
#include<string.h>
const long long N=5010;
const long long M=80000;
const long long INF=1<<30;
struct Edge
{
    long long v,next,w;
}e[M];
long long head[N],cnt;
long long n,m;
long long s,t;
long long pre[N],cur[N],dis[N],gap[N];
void addedge(long long u,long long v,long long w)
{
    e[cnt].v=v;    e[cnt].w=w;    e[cnt].next=head[u];
    head[u]=cnt++;
    e[cnt].v=u;    e[cnt].w=0;    e[cnt].next=head[v];
    head[v]=cnt++;
}
long long sap(long long n)
{
    long long i,v,u,flow=0,aug=INF;
    long long flag;
    for (i=1;i<=n;i++)
    {
        gap[i]=dis[i]=0;
        cur[i]=head[i];
    }
    gap[0]=n; //gap[s]=n;
    u=pre[s]=s;
    while (dis[s]<n){
        flag=0;
        for (long long j=cur[u];j!=-1;j=e[j].next){
            v=e[j].v;
            if (e[j].w>0&&dis[u]==dis[v]+1){
                flag=1;
                if (e[j].w<aug) aug=e[j].w;
                pre[v]=u;
                u=v;
                if (u==t){
                    flow+=aug;
                    while (u!=s){
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
        if (flag) continue;
        long long mindis=n;
        for (long long j=head[u];j!=-1;j=e[j].next){
            v=e[j].v;
            if (e[j].w>0&&mindis>dis[v]){
                mindis=dis[v];
                cur[u]=j;
            }
        }
        if (--gap[dis[u]]==0) break;
        dis[u]=mindis+1;
        ++gap[dis[u]];
        u=pre[u];
    }
   return flow;
}
bool vis[N];
long long ans,sum;
void dfs(long long s,long long t)
{
	if(s==t)return;
	vis[s]=1;
	ans++;
	for(long long i=head[s];i!=-1;i=e[i].next)
		if(! vis[e[i].v] && e[i].w)dfs(e[i].v,t);
}
int main()
{
	while (scanf("%lld%lld",&n,&m)!=-1)
	{
		ans=sum=0;
		s=n+1,t=n+2;
		cnt=0;
	   	memset(head,-1,sizeof(head));
		for(long long i=1;i<=n;i++)
		{
			long long a;
			scanf("%lld",&a);
			if(a>0)
			{
				addedge(s,i,a);
				sum+=a;
			}
			else addedge(i,t,-a);
		}
		while (m--)
		{
			long long u,v;
			scanf("%lld %lld",&u,&v);
			addedge(u,v,INF);
		}
		long long anss=sap(n+2);
		memset(vis,0,sizeof(vis));
		dfs(s,t);
		printf("%lld %lld\n",ans-1,sum-anss);
	}
	
	return 0;
}