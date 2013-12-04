#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define PI acos(-1)
#define INF 1<<30
#define EPS 1e-6
#define SET(a,b) memset(a,b,sizeof(a))
#define N 10010
#define M 10010
struct point
{
	double x,y;
	int init(){return scanf("%lf %lf",&x,&y);}
	point(double _x=0.0,double _y=0.0) :x(_x),y(_y){}
	point operator - (point v){ return point(x-v.x,y-v.y);}
	double operator * (point v){ return x*v.x+y*v.y;}
	double sqrx() {return sqrt(x*x+y*y);}
}cir,p[6],a;
double v0,sit,t,g,r;
double dist(point a,point b){ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }
double distp(point a,point b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
double xmult(point p1,point p2,point p0){ return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x); }
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
			/((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
void intersection_line_circle(point c,double r,point l1,point l2,point &p1,point &p2)
{
	point p=c;
	double t;
	p.x+=l1.y-l2.y; p.y+=l2.x-l1.x;
	p=intersection(p,c,l1,l2);
	t=sqrt(r*r-distp(p,c))/dist(l1,l2);
	p1.x=p.x+(l2.x-l1.x)*t; p1.y=p.y+(l2.y-l1.y)*t;
	p2.x=p.x-(l2.x-l1.x)*t; p2.y=p.y-(l2.y-l1.y)*t;
}
point ptoseg(point p,point l1,point l2)
{
	point t=p;
	t.x+=l1.y-l2.y; t.y+=l2.x-l1.x;
	if(xmult(l1,t,p)*xmult(l2,t,p)>EPS) return dist(p,l1)<dist(p,l2)?l1:l2;
	return intersection(p,t,l1,l2);
}
double Direct_Triangle_Circle_Area(point a,point b,point o,double r)
{
	double sign=1.0;
	a=a-o; b=b-o;
	o=point(0,0);
	if(fabs(xmult(a,b,o))<EPS) return 0;
	if(distp(a,o)>distp(b,o)){	swap(a,b);	sign=-1.0;	}
	if(distp(a,o)<r*r+EPS)
	{
		if(distp(b,o)<r*r+EPS) return xmult(a,b,o)/2.0*sign;
		point p1,p2;
		intersection_line_circle(o,r,a,b,p1,p2);
		if(dist(p1,b)>dist(p2,b)) swap(p1,p2);
		double ret1=fabs(xmult(a,p1,o));
		double ret2=acos(p1*b/p1.sqrx()/b.sqrx())*r*r;
		double ret=(ret1+ret2)/2.0;
		if(xmult(a,b,o)<EPS && sign>0.0 || xmult(a,b,o)>EPS && sign<0.0) ret=-ret;
		return ret;
	}
	point ins=ptoseg(o,a,b);
	if(distp(o,ins)>r*r-EPS)
	{
		double ret=acos(a*b/a.sqrx()/b.sqrx())*r*r/2;
		if(xmult(a,b,o)<EPS && sign>0.0 || xmult(a,b,o)>EPS && sign<0.0) ret=-ret;
		return ret;
	}
	point p1,p2;
	intersection_line_circle(o,r,a,b,p1,p2);
	double cm=r/(dist(o,a)-r);
	point m=point((o.x+cm*a.x)/(1+cm),(o.y+cm*a.y)/(1+cm));
	double cn=r/(dist(o,b)-r);
	point n=point((o.x+cn*b.x)/(1+cn),(o.y+cn*b.y)/(1+cn));
	double ret1=acos(m*n/m.sqrx()/n.sqrx())*r*r;
	double ret2=acos(p1*p2/p1.sqrx()/p2.sqrx())*r*r-fabs(xmult(p1,p2,o));
	double ret=(ret1-ret2)/2;
	if(xmult(a,b,o)<EPS && sign>0.0 || xmult(a,b,o)>EPS && sign<0.0) ret=-ret;
	return ret;
}
/**/
int main ()
{
	while (p[1].init()!=-1)
	{
		p[2].init(); p[3].init(); cir.init();
		p[4]=p[1];
		scanf("%lf",&r);
		double ans=0;
		for(int i=1;i<=3;i++)
			ans+=Direct_Triangle_Circle_Area(p[i],p[i+1],cir,r);
		printf("%.2f\n",fabs(ans));
	}
	return 0;
}