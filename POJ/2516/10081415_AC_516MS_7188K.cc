#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define N 510
#define inf 1<<30
int e[N][N]; //流 
int p[N][N]; //费用 
int pre[N]; 
int dis[N]; 
bool vis[N]; 
bool spfa(int s,int t,int n) 
{
	int i,u;    
	queue<int>q;    
	for(i=0;i<=n;i++) dis[i]=inf;
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
    	u=q.front(); q.pop();
    	vis[u]=0;       
    	for(i=0;i<=n;i++)
    	{
    		if(e[u][i]<=0||p[u][i]==inf) continue;
    		if(dis[i]>dis[u]+p[u][i])
    		{
    			dis[i]=dis[u]+p[u][i];pre[i]=u;
    			if(vis[i]==0)  q.push(i),vis[i]=1;
    		}
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
		for(i=t;i!=s;i=pre[i]) e[pre[i]][i]-=1,e[i][pre[i]]+=1;
		maxflow+=dis[t];
	}
	return maxflow;
} 

int sum[N]={0},flag,a[N][N],b[N][N],f[N][N][N];
int n,m,k,ans,saber,flow,s,t;	

int main()
{
	//freopen("1.in","r",stdin);
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
        s=0; t=m+n+1; saber=0;
        for(int z=1;z<=k;z++)
        {
        	memset(e,0,sizeof(e));
        	memset(p,0,sizeof(p));
		    for(int i=1;i<=m;i++)
		    {
		    	e[s][i]=b[i][z];
		    	p[s][i]=0;
		    }
		    for(int i=1;i<=m;i++)
		    for(int j=m+1;j<=m+n;j++)
		    {
		    	e[i][j]=b[i][z];
		    	p[i][j]=f[z][j-m][i];
		    	p[j][i]=-p[i][j];
		    }
		    for(int i=m+1;i<=m+n;i++)
		    {
		    	e[i][t]=a[i-m][z];
		    	p[i][t]=0;
		    }
		    saber+=ek(s,t,m+n+1);
		}
        printf("%d\n",saber);
    }
    return 0;
}