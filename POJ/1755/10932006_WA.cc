#include <cstdio>
#include <cstring>
#include <cmath>
#define N 110
#define EPS 1e-8
#define INF 12345678
int n,cnt,curcnt;
struct point
{
	double x,y;
}p[N],q[N];
double a[N],b[N],c[N];
inline point intersect(point p1,point p2,double a,double b,double c)
{
	double u=fabs(a*p1.x+b*p1.y+c);
	double v=fabs(a*p2.x+b*p2.y+c);
	point poi;
	poi.x=(p1.x*v+p2.x*u)/(u+v);
	poi.y=(p1.y*v+p2.y*u)/(u+v);
	return poi;
}
inline void cut(double a,double b,double c)
{
	int i;
	curcnt=0;
	for(i=1;i<=cnt;i++)
	{
		if(a*p[i].x+b*p[i].y+c>-EPS) q[++curcnt]=p[i];
		else
		{
			if(a*p[i-1].x+b*p[i-1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i-1],a,b,c);
			if(a*p[i+1].x+b*p[i+1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i+1],a,b,c);
		}
	}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];
	p[0]=q[curcnt];
	cnt=curcnt;
}
double xmult(point p0,point p1,point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double areas(point *a)
{
	double sum=0;
	for(int i=2;i<cnt;i++)
		sum+=xmult(p[1],p[i],p[i+1]);
	return -sum/2.0;
}
int main ()
{
	while(scanf("%d",&n)!=-1)
	{
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
		for(int i=0;i<n;i++)
		{
			int j;
			p[1].x=p[1].y=p[2].x=p[4].y=0;
			p[2].y=p[4].x=p[3].x=p[3].y=INF;
			p[0]=p[4]; p[5]=p[1];
			cnt=4;
			for(j=0;j<n;j++)
			if(j!=i)
			{
				double a0=(a[i]-a[j])/(a[i]*a[j]),
					   b0=(b[i]-b[j])/(b[i]*b[j]),
					   c0=(c[i]-c[j])/(c[i]*c[j]);
				if(a0==0 && b0==0 && c0<EPS) break;
				cut(a0,b0,c0);
				if(fabs(areas(p))<EPS) break;
			}
			if(j<n) printf("NO\n");
			else printf("YES\n");
		}
	}	
	return 0;
}