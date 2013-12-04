#include <cstdio>
#include <cmath>
#include <cstring>
#define N 110
#define SET(a,b) memset(a,b,sizeof(a))
#define INF 0x5fffffff
int cx[N],cy[N],sx[N],sy[N];
double lx[N],ly[N];
int nx,ny;
double g[N][N];
bool dfs(int u)
{
	sx[u]=1;
	for(int v=1;v<=ny;v++)
		if(g[u][v]==lx[u]+ly[v] && ! sy[v])
		{
			sy[v]=1;
			if(!cy[v] || dfs(cy[v]))
			{	cx[u]=v;	cy[v]=u;		return 1;		}
		}
	return 0;
}
void KM()
{
	int i,j,u;
	double minn;
	SET(cx,0); SET(cy,0); SET(ly,0);
	for(i=1;i<=nx;i++) lx[i]=-INF;
	for(i=1;i<=nx;i++)	for(j=1;j<=ny;j++)		if(lx[i]<g[i][j]) lx[i]=g[i][j];
	for(u=1;u<=nx;u++)
	if(! cx[u])
	{
		SET(sx,0); SET(sy,0);
		while (! dfs(u))
		{
			minn=-INF;
			for(i=1;i<=nx;i++)	if(sx[i])
			for(j=1;j<=ny;j++)
				if(! sy[j] && lx[i]+ly[j]-g[i][j]<minn) minn=lx[i]+ly[j]-g[i][j];
			for(i=1;i<=nx;i++)		if(sx[i]) { lx[i]-=minn; sx[i]=0; } 
			for(i=1;i<=ny;i++)		if(sy[i]) { ly[i]+=minn; sy[i]=0; }
		}
	}
	for(i=1;i<=nx;i++)printf("%d\n",cx[i]);
}
struct point
{
	double x,y;
	void init(){scanf("%f%f",&x,&y);}
}p[N],q[N];
int main()
{
	int n,i,j;
	while (scanf("%d",&n)!=EOF)
	{	nx=ny=n;
		for(i=1;i<=n;i++) p[i].init();
		for(i=1;i<=n;i++) q[i].init();
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			g[i][j]=-sqrt((p[i].x-q[i].x)*(p[i].x-q[i].x)+(p[i].y-q[i].y)*(p[i].y-q[i].y));
	KM();	}
	return 0;
}