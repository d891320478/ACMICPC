#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 310
#define M 310
#define SET(a,b) memset(a,b,sizeof(a))
#define INF 1<<30
int cx[N],cy[M],sx[N],sy[M],lx[N],ly[M];
int slack[M];
int nx,ny,g[N][M];
bool dfs(int u)
{
	sx[u]=1;
	for(int v=1;v<=ny;v++)
		if(! sy[v])
		{
			if(g[u][v]==lx[u]+ly[v])
			{
				sy[v]=1;
				if(!cy[v] || dfs(cy[v]))
				{	cx[u]=v;	cy[v]=u;		return 1;		}
			}
			else slack[v]=min(slack[v],lx[u]+ly[v]-g[u][v]);
		}
	return 0;
}
int KM()
{
	int i,j,u,minn,ans=0;
	SET(cx,0); SET(cy,0);
	SET(lx,0); SET(ly,0);
	for(i=1;i<=nx;i++)
	for(j=1;j<=ny;j++)
		if(lx[i]<g[i][j]) lx[i]=g[i][j];
	for(u=1;u<=nx;u++)
	if(! cx[u])
	{
		SET(slack,0x7f);
		SET(sx,0);
		SET(sy,0);
		while (! dfs(u))
		{
			minn=INF;
			for(j=1;j<=ny;j++)
				if(! sy[j])	if(minn>slack[j]) minn=slack[j];
			for(i=1;i<=nx;i++) if(sx[i]) { lx[i]-=minn; sx[i]=0; } 
			for(i=1;i<=ny;i++) 
				if(sy[i]) { ly[i]+=minn; sy[i]=0; }
				else slack[i] -= minn;
		}
	}
	for(i=1;i<=nx;i++)	ans+=g[i][cx[i]];
	return -ans;
}
int n,m;
char s[N],ch;
int a[N][2],b[N][2];
int main ()
{
	while (scanf("%d %d&c",&n,&m,&ch) && n+m)
	{
		nx=ny=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",&s);
			for(int j=0;s[j];j++)
				if(s[j]=='m')
				{
					nx++;
					a[nx][0]=i,a[nx][1]=j;
				}
				else
				if(s[j]=='H')
				{
					ny++;
					b[ny][0]=i,b[ny][1]=j;
				}
		}
		for(int i=1;i<=nx;i++)
		for(int j=1;j<=ny;j++)
			g[i][j]=-(abs(a[i][0]-b[j][0])+abs(a[i][1]-b[j][1]));
		printf("%d\n",KM());
	}
	
	return 0;
}