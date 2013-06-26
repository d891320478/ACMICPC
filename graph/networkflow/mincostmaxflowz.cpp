#define N 510
#define inf 1<<30
int e[N][N]; //流
int p[N][N]; //费用 
int pre[N]; int dis[N]; bool vis[N]; 
bool spfa(int s,int t,int n) 
{
	int i,u;   queue<int>q;    for(i=0;i<=n;i++) dis[i]=inf;
    memset(pre,-1,sizeof(pre));    memset(vis,0,sizeof(vis));    dis[s]=0;    q.push(s);
    while(!q.empty())
    {
    	u=q.front(); q.pop();    	vis[u]=0;       
    	for(i=0;i<=n;i++)
    	{
    		if(e[u][i]<=0||p[u][i]==inf) continue;
    		if(dis[i]>dis[u]+p[u][i])
    		{	dis[i]=dis[u]+p[u][i];   pre[i]=u;	if(vis[i]==0)  q.push(i),vis[i]=1;  }
    	}
    }
    if(pre[t]!=-1) return 1;
    return 0;
}
int ek(int s,int t,int n)
{
	int u,i;		int maxflow=0;    
	while(spfa(s,t,n)) 
	{  for(i=t;i!=s;i=pre[i]) e[pre[i]][i]-=1,e[i][pre[i]]+=1;	maxflow+=dis[t];	}
	return maxflow;
}
