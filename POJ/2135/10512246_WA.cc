#include <cstdio>
#include <cstring>
const int maxn=1010;
const int inf=2000000000;
int c[maxn][maxn],f[maxn][maxn],w[maxn][maxn],pnt[maxn];
int value[maxn],d[maxn],mk[maxn],open[maxn];
int n,m,flow,cost;
void mincost(int n,int s,int t,int &flow,int &cost)
{
	int tail,i,j,u,v;
	memset(f,0,sizeof(f));
	flow=cost=0;
	do{
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++) value[i]=inf;
		open[0]=s; d[s]=inf; tail=value[s]=0;
		while (tail>=0)
		{
			u=open[tail];
			tail--;
			mk[u]=0;
			for(v=1;v<=n;v++)
				if(f[u][v]<c[u][v] && value[u]<inf && value[u]+w[u][v]<value[v])
				{
					if(! mk[v]) mk[v]=1,open[++tail]=v;
					pnt[v]=u;
					value[v]=value[u]+w[u][v];
					d[v]=d[u]<c[u][v]-f[u][v]?d[u]:c[u][v]-f[u][v];
				}
		}
		if(value[t]==inf) return;
		flow+=d[t]; cost+=d[t]*value[t];
		for(u=t;u!=s;)
		{
			v=u; u=pnt[v];
			f[u][v]+=d[t];
			f[v][u]=-f[u][v];
			if(f[u][v]<0)w[u][v]=-w[v][u];
			else if(f[v][u]<0)w[v][u]=-w[u][v];
		}
	}while(d[t]>0);
}
int main ()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		memset(c,0,sizeof(c));
		memset(w,0,sizeof(w));
		c[1][2]=c[n+1][n+2]=2;
		w[1][2]=w[n+1][n+2]=0;
		n+=2;
		for(int i=1;i<=m;i++)
		{
			int ue,ve,we;
			scanf("%d%d%d",&ue,&ve,&we);
			ue++,ve++;
			c[ue][ve]=c[ve][ue]=1;
			if(w[ue][ve]==0 || we<w[ue][ve])w[ue][ve]=w[ve][ue]=we;
		}
		mincost(n,1,n,flow,cost);
		printf("%d\n",cost);
	}
	
	return 0;
}