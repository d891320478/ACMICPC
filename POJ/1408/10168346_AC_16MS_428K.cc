#include <cstdio>
#include <cmath>
int n;
struct point
{
	double x,y;
}a[35],b[35],c[35],d[35],poi[40][40];
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
double s(point u,point v,point w)
{
	return fabs(u.x*v.y+v.x*w.y+w.x*u.y-v.y*w.x-u.y*v.x-u.x*w.y)/2.0;
}
double f(point h,point i,point j,point k)
{
	return s(h,i,j)+s(h,j,k);
}
int main()
{
	while (scanf("%d",&n) && n)
	{
		double xx;
		a[0].x=a[0].y=a[n+1].y=0.0; a[n+1].x=10000000.0;
		b[0].x=0.0; b[0].y=b[n+1].y=b[n+1].x=10000000.0;
		c[0].x=c[0].y=c[n+1].x=0.0; c[n+1].y=10000000.0;
		d[0].x=d[n+1].x=d[n+1].y=10000000.0; d[0].y=0.0;
		for(int j=1;j<=n;j++)
		{ scanf("%lf",&xx); a[j].x=xx*10000000.0; a[j].y=0.0;	}
		for(int j=1;j<=n;j++)
		{ scanf("%lf",&xx); b[j].x=xx*10000000.0; b[j].y=10000000.0; }
		for(int j=1;j<=n;j++)
		{ scanf("%lf",&xx); c[j].y=xx*10000000.0; c[j].x=0.0;	}
		for(int j=1;j<=n;j++)
		{ scanf("%lf",&xx); d[j].y=xx*10000000.0; d[j].x=10000000.0; }
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++)
			poi[i][j]=intersection(a[i],b[i],c[j],d[j]);
		double ans=0.0;
		for(int i=0;i<n+1;i++)
		for(int j=0;j<n+1;j++)
		{
			double s=f(poi[i][j],poi[i+1][j],poi[i+1][j+1],poi[i][j+1]);
			ans=ans>s?ans:s;
		}
		printf("%.6f\n",ans/10000000.0/10000000.0);
	}
	
	return 0;
}