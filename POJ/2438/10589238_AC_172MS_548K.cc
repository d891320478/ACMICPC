#include <cstdio>
#include <cstring>
#define maxn 410
void dirac(bool g[maxn][maxn],int n,int *path)
{
	static int nxt[maxn];
	static bool vis[maxn];
	memset(nxt,255,sizeof(nxt));
	memset(vis,0,sizeof(vis));
	int S=0,T;
	for(T=1;! g[S][T];T++);
	nxt[S]=T;
	nxt[T]=S;
	vis[S]=vis[T]=1;
	for(int num=2;num!=n;)
	{
		while (1)
		{
			bool ok=1;
			for(int i=0;i<n;i++)
			{
				if(vis[i])continue;
				if(g[i][S])	vis[i]=1,nxt[i]=S,S=i,ok=0,num++;
				else if(g[T][i]) vis[i]=1,nxt[T]=i,T=i,ok=0,num++;
			}
			if(ok)break;
		}
		nxt[T]=S;
		if(! g[S][T])
		{
			int tgt=-1;
			int prev=S,next;
			for(int i=nxt[S];nxt[i]!=T;i=next)
			{
				next=nxt[i];
				nxt[i]=prev;
				prev=i;
				if(g[S][next] && g[T][i])
				{
					tgt=i;
					break;
				}
			}
			nxt[S]=next;
			nxt[T]=tgt;
			S=tgt;
		}
		if(num==n)break;
		bool ffff=0;
		for(int i=0;i<n;i++)
		{
			if(vis[i])continue;
			int j=S;
			do{
				if(g[i][j])
				{
					T=j;
					S=nxt[j];
					ffff=1;
					break;
				}
			}while((j=nxt[j])!=S);
			if(ffff)break;
		}
	}
	int len=0,i=S;
	do{
		path[len++]=i;
	}while((i=nxt[i])!=S);
}
int n,m;
int a[maxn];
bool g[maxn][maxn];
int main()
{
	while (scanf("%d%d",&n,&m)!=-1)
	{
		if(n==0 && m==0)break;
		n*=2;
		memset(g,1,sizeof(g));
		while (m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u-1][v-1]=g[v-1][u-1]=0;
		}
		dirac(g,n,a);
		for(int i=0;i<n-1;i++)
			printf("%d ",a[i]+1);
		printf("%d\n",a[n-1]+1);
	}
	
	return 0;
}