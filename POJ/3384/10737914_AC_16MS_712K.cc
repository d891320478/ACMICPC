#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 1510
#define EPS 1e-10
struct point
{	double x,y;	}inp[N],p[N],q[N],o1,o2;
int n;	double r;	int cnt,curcnt;
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
		if(a*p[i].x+b*p[i].y+c>=0.0) q[++curcnt]=p[i];
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
inline void solve(double r)//注意：默认点是顺时针，如果题目不是顺时针，规整化方向
{
	for(int i=1;i<=n;i++)//向内推进R
	{
		point ta,tb,tt;  
        tt.x = inp[i+1].y - inp[i].y;  
        tt.y = inp[i].x - inp[i+1].x;  
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);  
        tt.x = tt.x * k;  
        tt.y = tt.y * k;  
        ta.x = inp[i].x + tt.x;  
        ta.y = inp[i].y + tt.y;  
        tb.x = inp[i+1].x + tt.x;  
        tb.y = inp[i+1].y + tt.y;
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
	}
}
inline void gzh() //规整化方向，逆时针变顺时针，顺时针变逆时针
{
	for(int i=1;i<(n+1)/2;i++)	 swap(inp[i],inp[n-i]);	inp[n+1]=inp[1];
}
double area(point *p,int n)//有向面积，顺时针为负，逆时针为正
{
	double s=0.0;
	for(int i=1;i<=n;i++)	s+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
	return s;
}
double ma=-1;
int main ()
{
	int j,i;
	scanf("%d%lf",&n,&r);
	for(i=1;i<=n;i++) scanf("%lf%lf",&inp[i].x,&inp[i].y);
	inp[n+1]=inp[1];		if(area(inp,n)>0.0) gzh();
	for(int i=1;i<=n;i++) p[i]=inp[i];
	p[n+1]=p[1];	p[0]=p[n];	cnt=n;
	solve(r);
	for(i=1;i<=cnt;i++)
	for(j=1;j<=cnt;j++)
	{
		double t=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
		if(ma<=t)
		{
			ma=t;
			o1=p[i];
			o2=p[j];
		}
	}
	if(o1.x>o2.x)swap(o1,o2);
	printf("%.4f %.4f %.4f %.4f\n",o1.x,o1.y,o2.x,o2.y);
	
	return 0;
}