#include <cstdio>
#include <cmath>
#define PI 3.141592653
struct point
{
	double x,y;
}a,b,c;
struct line
{
	point a,b;
}u,v;
double r;
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point intersection(line u,line v)
{
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))/
			 ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}
point incenter(point a,point b,point c)
{
	line u,v;
	u.a.x=(a.x+b.x)/2.0;
	u.a.y=(a.y+b.y)/2.0;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a.x=(a.x+c.x)/2.0;
	v.a.y=(a.y+c.y)/2.0;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u,v);
}
int main ()
{
	while (scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=1)
	{
		r=dis(incenter(a,b,c),a);
		printf("%.2f\n",2*r*PI);
	}
	
	return 0;
}