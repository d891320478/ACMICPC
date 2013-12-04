#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 510
#define inf 1<<30
int e[N][N]; //流
int p[N][N]; //费用 
int pre[N]; int dis[N]; bool vis[N];
int ans;
int n,m,kk;
bool spfa(int s,int t,int n) 
{
	int i,u;    
	queue<int>q;    
	for(i=1;i<=n;i++) dis[i]=inf;
    memset(pre,-1,sizeof(pre));    memset(vis,0,sizeof(vis));    dis[s]=0;    q.push(s);
    while(!q.empty())
    {
    	u=q.front(); q.pop();    	vis[u]=0;       
    	for(i=1;i<=n;i++)
    	{
    		if(e[u][i]<=0||p[u][i]==inf) continue;
    		if(dis[i]>dis[u]+p[u][i])
    		{	dis[i]=dis[u]+p[u][i];   pre[i]=u;	if(vis[i]==0)  q.push(i),vis[i]=1;  		}
    	}
    }
    if(pre[t]!=-1) return 1;
    return 0;
}
int ek(int s,int t,int n)
{
	int u,i;
	int maxflow=0;    
	while(spfa(s,t,n)) 
	{
		if(dis[t]>kk) return 0;
		ans++;       
		for(i=t;i!=s;i=pre[i]) e[pre[i]][i]-=1,e[i][pre[i]]+=1;		maxflow+=dis[t];
	}
	return maxflow;
}
int main ()
{
	int i;
	while (scanf("%d%d%d",&n,&m,&kk))
	{
		if(n+m+kk==0)break;
		memset(e,0,sizeof(e));
		memset(p,0,sizeof(p));
		for(i=1;i<=n;i++)
		{
			e[i][i+n]=1;
			p[i][i+n]=0;
		}
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			e[u+n][v]=inf;
			p[u+n][v]=1;
			p[v][u+n]=-1;
		}
		ans=0;
		ek(n+1,n,n*2);
		printf("%d\n",ans);
	}
	
	return 0;
}