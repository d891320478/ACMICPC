#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define N 110
#define SET(a,b) memset(a,b,sizeof(a))
#define INF (1<<29)
int cx[N],cy[N],sx[N],sy[N];
int lx[N],ly[N];
int slack[N],g[N][N];
int n,nx,ny;
int idx[N],idy[N];
bool dfs(int u)
{
	sx[u]=1;
	for(int v=1;v<=ny;++v)
	if(! sy[v])
	{
		int tmp=lx[u]+ly[v]-g[u][v];
		if(tmp==0)
		{
			sy[v]=1;
			if(! cy[v] || dfs(cy[v]))
			{
				cx[u]=v;
				cy[v]=u;
				return 1;
			}
		}
		else
		slack[v]=min(slack[v],tmp);
	}
	return 0;
}
double KM()
{
	int i,j,u;
	int minn;
	SET(cx,0);
	SET(cy,0);
	for(i=1;i<=nx;++i) lx[i]=-INF;
	for(i=1;i<=ny;++i) ly[i]=0;
	for(i=1;i<=nx;++i)
	for(j=1;j<=ny;++j)
		if(g[i][j]>lx[i]) lx[i]=g[i][j];
	for(u=1;u<=nx;++u)
	if(! cx[u])
	{
		for(i=1;i<=ny;++i)
			slack[i]=INF;
		SET(sx,0);
		SET(sy,0);
		while(! dfs(u))
		{
			minn=INF;
			for(j=1;j<=ny;++j)
			if(! sy[j]) minn=min(minn,slack[j]);
			for(i=1;i<=nx;++i)
			if(sx[i])
			{
				lx[i]-=minn;
				sx[i]=0;
			}
			for(i=1;i<=ny;++i)
			if(sy[i])
			{
				ly[i]+=minn;
				sy[i]=0;
			}
			else slack[i]-=minn;
		}
		//printf("%d %d\n",u,cx[u]);
	}
	double ans=0;
	for(i=1;i<=nx;++i)
		ans+=sqrt(-1.0*g[i][cx[i]]);
	return ans;
}
int b1,b2;
struct point
{
	int x,y;
	void init()
	{
		scanf("%d%d",&x,&y);
	}
}p[N];
int dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int path[N];
void find(int u)
{
	//printf("u = %d\n",u);
	if(u==1 || u==2) path[++path[0]]=0;
	else path[++path[0]]=u-2;
	if(cx[u]==n || cx[u]==n-1) return;
	int x=cx[u];
	x=idy[x];
	++x;
	find(x);
}
int main()
{
	int _=0;
	while(scanf("%d",&n)!=-1)
	{
		if(! n) break;
		nx=ny=n;
		idx[1]=1;
		idy[ny]=n;
		for(int i=1;i<ny;++i)
		{
			idx[i+1]=i;
			idy[i]=i+1;
		}
		for(int i=1;i<=n;++i) p[i].init();
		for(int i=1;i<=nx;++i)
		for(int j=1;j<=ny;++j)
		{
			if(idy[j]<=idx[i]) g[i][j]=-INF;
			else g[i][j]=-dist(p[idx[i]],p[idy[j]]);
		}
		/*
		for(int i=1;i<=nx;++i)
		{
			for(int j=1;j<=ny;++j)
				printf("%d ",g[i][j]);
			printf("\n");
		}
		*/
		printf("%.2f\n",KM());
		/*
		for(int i=1;i<=n;++i)
			printf("%d %d\n",cx[i],cy[i]);
		*/
	}
	return 0;
}