#include <cstdio>
#include <cmath>
#include <cstring>
#define N 1010
int n,pre[N];
struct point 
{
	double x,y,z;
}p[N];
double a[N][N],d[N],value,l,r;
bool vis[N];
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double prim()
{
	int i,j;
	double cost=0.0,len=0.0;
	for(i=1;i<=n;i++)
	{
		d[i]=a[1][i];
		vis[i]=0;
		pre[i]=1;
	}
	vis[1]=1;
	for(i=1;i<n;i++)
	{
		double min=1e10;
		int k;
		for(j=1;j<=n;j++)
			if(! vis[j])
			if(min>d[j])
			{
				min=d[j];
				k=j;
			}
		vis[k]=1;
		cost+=fabs(p[k].z,p[pre[k]].z);
		len+=dis(p[k],p[pre[k]]);
		for(j=1;j<=n;j++)
			if (! vis[j])
			if(a[k][j]<d[j])
			{
				d[j]=a[k][j];
				pre[j]=k;
			}
	}
	return cost/len;
}
int main ()
{
	int i,j;
	while (scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
			a[i][i]=0.0;
		}
		l=0;
		while (1)
		{
			for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				a[i][j]=a[j][i]=fabs(p[i].z-p[j].z)-l*dis(p[i],p[j],l);
			r=prim();
			if(fabs(r-l)<=0.0001)break;
			l=r;
		}
		printf("%.3f\n",l);
	}
	
	return 0;
}