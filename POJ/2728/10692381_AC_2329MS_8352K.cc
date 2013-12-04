#include <cstdio>
#include <cmath>
#include <cstring>
#define N 1010
int n;
struct point 
{
	double x,y,z;
}p[N];
double a[N][N],d[N],l,r,mid,value;
bool vis[N];
double dis(point a,point b)
{
	return fabs(a.z-b.z)-mid*sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void prim()
{
	int i,j;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for(i=1;i<=n;i++)
		d[i]=a[1][i];
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
		value+=d[k];
		for(j=1;j<=n;j++)
			if (! vis[j])
			if(a[k][j]<d[j])
				d[j]=a[k][j];
	}
}
int main ()
{
	int i,j;
	while (scanf("%d",&n) && n)
	{
		for(i=1;i<=n;i++)
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		l=0;
		r=100;
		while (1)
		{
			mid=(l+r)/2.0;
			for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
				a[i][j]=a[j][i]=dis(p[i],p[j]);
			value=0.0;
			prim();
			if(fabs(value-0.0)<=0.0001)break;
			if(value-0.0>0.0001) l=mid;
			else r=mid;
		}
		printf("%.3f\n",mid);
	}
	
	return 0;
}