#include <cstdio>
#include <cstring>
const int maxn=510;
const int inf=0x3fffffff;
int c[maxn][maxn],f[maxn][maxn],w[maxn][maxn],pnt[maxn];
int value[maxn],d[maxn],mk[maxn],open[maxn],oldque[maxn];

void mincost(int n,int s,int t,int &flow,int &cost)
{
	int cur,tail,tl,i,j,u,v;
	memset(f,0,sizeof(f));
	memset(pnt,0,sizeof(pnt));
	memset(open,0,sizeof(open));
	flow=cost=0;
	do{
		memset(d,0,sizeof(d));
		for(i=1;i<=n;i++) value[i]=inf;
		open[0]=s; d[s]=inf; tail=value[s]=0;
		while(tail>=0)
		{
			memset(mk,0,sizeof(mk));
			memcpy(oldque,open,sizeof(open));
			for(tl=tail,pnt[s]=cur=0,tail=-1;cur<=tl;cur++)
			for(u=oldque[cur],v=1;v<=n;v++)
				if(f[u][v]<c[u][v] && value[u]<inf && value[u]+w[u][v]<value[v])
				{
					if(! mk[v]){mk[v]=1; open[++tail]=v;}
					pnt[v]=u;
					value[v]=value[u]+w[u][v];
					if(d[u]<c[u][v]-f[u][v])d[v]=d[u];
					else d[v]=c[u][v]-f[u][v];
				}
		}
		if(value[t]>=inf) return;
		flow+=d[t]; cost+=d[t]*value[t];
		for(u=t;u!=s;)
		{
			v=u; u=pnt[v];
			f[u][v]+=d[t];
			f[v][u]-=f[u][v];
			if(f[u][v]<0)w[u][v]=-w[v][u];
			else if(f[v][u]<0)w[v][u]=-w[u][v];
		}
	}while(d[t]>0);
}

int sum,flag,a[maxn][maxn],b[maxn][maxn],e[maxn][maxn][maxn];
int n,m,k,ans,saber,flow,s,t;	

int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
    	if(n==0 && m==0 && k==0)break;
    	for(int i=1;i<=n;i++)
    	for(int j=1;j<=k;j++)
    		scanf("%d",&a[i][j]);
    	for(int i=1;i<=m;i++)
    	for(int j=1;j<=k;j++)
    		scanf("%d",&b[i][j]);
    	for(int i=1;i<=k;i++)
    	for(int j=1;j<=n;j++)
    	for(int l=1;l<=m;l++) 
    		scanf("%d",&e[i][j][l]);
    	flag=1;
    	for(int i=1;i<=k;i++)
    	{
    		sum=0;
    		for(int j=1;j<=n;j++) sum+=a[j][i];
    		for(int j=1;j<=m;j++) sum-=b[j][i];
    		if(sum>0){flag=0; break;}
    	}
    	if(!flag){printf("-1\n");continue;}
        s=1; t=m+n+2; saber=0;
        for(int z=1;z<=k;z++)
        {
        	memset(c,0,sizeof(c));
        	memset(w,0,sizeof(w));
		    for(int i=1;i<=m;i++)
		    {
		    	c[s][i+1]=b[i][z];
		    	w[s][i+1]=0;
		    }
		    for(int i=1;i<=m;i++)
		    for(int j=m+1;j<=m+n;j++)
		    {
		    	c[i+1][j+1]=inf;
		    	w[i+1][j+1]=e[z][j-m][i];
		    	w[j+1][i+1]=-w[i+1][j+1];
		    }
		    for(int i=m+1;i<=m+n;i++)
		    {
		    	c[i+1][t]=a[i-m][z];
		    	w[i+1][t]=0;
		    }
		    mincost(m+n+2,s,t,flow,ans);
		    saber+=ans;
		}
        printf("%d\n",saber);
    }
    return 0;
}