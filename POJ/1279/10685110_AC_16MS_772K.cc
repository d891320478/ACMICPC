/*半平面相交（直线切割多边形）（点标号从1开始）*/  
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 1510
#define EPS 1e-10
struct point
{
	double x,y;
}inp[N],p[N],q[N];
int n;
double r;
int cnt,curcnt;
inline void getline(point p1,point p2,double &a,double &b,double &c)
{
	a=p2.y-p1.y;
	b=p1.x-p2.x;
	c=p2.x*p1.y-p1.x*p2.y;
}
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
		if(a*p[i].x+b*p[i].y+c>=EPS) q[++curcnt]=p[i];
		else
		{
			if(a*p[i-1].x+b*p[i-1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i-1],a,b,c);
			if(a*p[i+1].x+b*p[i+1].y+c>EPS) q[++curcnt]=intersect(p[i],p[i+1],a,b,c);
		}
	}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];
	p[0]=p[curcnt];
	cnt=curcnt;
}
inline void solve()//注意：默认点是顺时针，如果题目不是顺时针，规整化方向
{
	double a,b,c;
	for(int i=1;i<=n;i++) p[i]=inp[i];
	p[n+1]=p[1];	p[0]=p[n];	cnt=n;
	for(int i=1;i<=n;i++)
	{
		getline(inp[i],inp[i+1],a,b,c);
		cut(a,b,c);
	}
}
inline void gzh() //规整化方向，逆时针变顺时针，顺时针变逆时针
{
	for(int i=1;i<(n+1)/2;i++)
		 swap(inp[i],inp[n-i]);
	inp[n+1]=inp[1];
}
double area(point *p,int n)
{
	double s=0.0;
	for(int i=1;i<=n;i++)
		s+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
	return s;
}
int main ()
{
	int tt,i;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lf%lf",&inp[i].x,&inp[i].y);
		inp[n+1]=inp[1];
		if(area(inp,n)>0) gzh();
		solve();
		printf("%.2f\n",fabs(area(p,cnt)/2.0));
	}
	
	return 0;
}