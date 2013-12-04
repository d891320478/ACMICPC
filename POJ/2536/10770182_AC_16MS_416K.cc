#include <cstdio>
#include <cstring>
#include <cmath>
#define N 110
#define M 150010
int n,m,p,cnt;
double s,v;
int head[N],next[M],e[M],u[N],h[N],q[N],va;
int dfs(int i)
{
    for(int j=head[i];j!=-1;j=next[j])
  		if(! u[e[j]])
  		{	u[e[j]]=1;
   			if( q[e[j]]==0 || dfs(q[e[j]]) )
   			{    	q[e[j]]=i;		h[i]=e[j];		return 1;		}
  		}
    return 0;
}
struct point
{
	double x,y;
	void init(){scanf("%lf%lf",&x,&y);}
}a[N],b[N];
double dist(int i,int j)
{
	return sqrt((a[i].x-b[j].x)*(a[i].x-b[j].x)+(a[i].y-b[j].y)*(a[i].y-b[j].y));
}
int main()
{
	int i,j;
	while(scanf("%d%d%lf%lf",&n,&m,&s,&v)!=-1)
	{
		memset(h,0,sizeof(h));	memset(q,0,sizeof(q));	memset(head,-1,sizeof(head));
		cnt=va=0;
		for(i=1;i<=n;i++) a[i].init();
		for(i=1;i<=m;i++) b[i].init();
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(dist(i,j)<=s*v)
			{
				next[cnt]=head[i];
				e[cnt]=j;
				head[i]=cnt++;
				if(! h[i])
				if(! q[j])
				{
					va++;
					h[i]=j;
					q[j]=i;
				}
			}
		for(i=1;i<=n;i++)
			if(! h[i])
			{
				memset(u,0,sizeof(u));
				if(dfs(i)) va++;
			}
		printf("%d\n",n-va);
	}
	return 0;
}