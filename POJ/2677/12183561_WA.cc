#include<cstdio>
#include<cstring>
#include<cmath>
#define N 110
#define SET(a,b) memset(a,b,sizeof(a))
#define INF (1e10)
#define EPS (1e-8)
int cx[N],cy[N],sx[N],sy[N];
double lx[N],ly[N];
double slack[N],g[N][N];
int n,nx,ny;
int idx[N],idy[N];
double min(double a,double b)
{
	return a-b>EPS?b:a;
}
bool dfs(int u)
{
	sx[u]=1;
	for(int v=1;v<=ny;++v)
	if(! sy[v])
	{
		double tmp=lx[u]+ly[v]-g[u][v];
		if(fabs(tmp)<EPS)
		{
			sy[v]=1;
			if(! cy[v] || dfs(cy[v]))
			{
				cx[u]=v;
				cy[v]=u;
				return 1;
			}
		}
		else slack[v]=min(slack[v],tmp);
	}
	return 0;
}
double KM()
{
	int i,j,u;
	double ans=0,minn;
	SET(cx,0);
	SET(cy,0);
	for(i=1;i<=nx;++i) lx[i]=-INF;
	for(i=1;i<=ny;++i) ly[i]=0;
	for(i=1;i<=nx;++i)
	for(j=1;j<=ny;++j)
		if(g[i][j]-lx[i]>EPS) lx[i]=g[i][j];
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
	for(i=1;i<=nx;++i)
		ans+=g[i][cx[i]];
	return ans;
}
int b1,b2;
struct point
{
	double x,y;
	void init()
	{
		scanf("%lf%lf",&x,&y);
	}
}p[N];
double dist(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	int _=0;
	while(scanf("%d",&n)!=-1)
	{
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
				printf("%.2lf ",g[i][j]);
			printf("\n");
		}
		*/
		printf("%.2lf\n",-KM());
	}
	return 0;
}