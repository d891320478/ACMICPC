#include <cstdio>
#include <iostream>
#define EPS 1e-8
using namespace std;
struct point
{
	double x,y;
}a,b,c,d,e,f,g,h,i;
double mult(point p0,point p1,point p2) 
{    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y); }
bool intersect(point u1,point u2,point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x) && max(v1.x,v2.x)>=min(u1.x,u2.x) && 
			max(u1.y,u2.y)>=min(v1.y,v2.y) && max(v1.y,v2.y)>=min(u1.y,u2.y) && 
			mult(u1,v1,u2)*mult(u1,u2,v2)>=0 && mult(v1,u1,v2)*mult(v1,v2,u2)>=0);
}
bool par(point u1,point u2,point v1,point v2)
{
	point l1,l2;
	l1.x=u2.x-u1.x; l1.y=u2.y-u1.y;
	l2.x=v2.x-v1.x; l2.y=v2.y-v1.y;
	return (l1.x*l2.y==l2.x*l1.y);
}
point intersection(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
point opoint(point poi,point a,point b)
{
	point xxx;
	xxx.x=a.x,xxx.y=poi.y;
	if(a.x==b.x)return xxx;
	if(poi.y==a.y)return a;
	if(poi.y==b.y)return b;
	double u=poi.y-a.y,v=b.y-poi.y;
	xxx.x=(u*b.x/v+a.x)/(1+u/v);
	return xxx;
}
int main ()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
		if(a.x==b.x || c.x==d.x)
		{
			cout<<"0.00"<<endl;
			continue;
		}
		if(! intersect(a,b,c,d))
		{
			cout<<"0.00"<<endl;
			continue;
		}
		if(par(a,b,c,d))
		{
			cout<<"0.00"<<endl;
			continue;
		}
		e=intersection(a,b,c,d);
		f=a.y>b.y?a:b;
		g=c.y>d.y?c:d;
		if((g.x>=e.x && f.x>=g.x && f.y>=g.y) || (g.x<=e.x && f.x<=g.x && f.y>=g.y))
		{
			cout<<"0.00"<<endl;
			continue;
		}
		if((f.x>=e.x && f.x<=g.x && f.y<=g.y) || (g.x<=e.x && f.x>=g.x && f.y<=g.y))
		{
			cout<<"0.00"<<endl;
			continue;
		}
		h=f.y<g.y?f:g;
		if(f.y==g.y) i=f;
		else if(f.y<g.y)i=opoint(f,c,d);
			 else i=opoint(g,a,b);
		double ans=mult(e,h,i);
		if(ans<0.0)ans=-ans;
		printf("%.2f\n",ans/2.0+EPS);
	}
	
	return 0;
}