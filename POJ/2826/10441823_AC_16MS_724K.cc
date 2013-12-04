#include <cstdio>
#include <iostream>
#define EPS 1e-8
using namespace std;
struct point
{
	double x,y;
}a,b,c,d,e,f,g,h,i,p[4];
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
	if(a.x==b.x)return (point){a.x,poi.y};
	if(poi.y==a.y)return a;
	if(poi.y==b.y)return b;
	double u=poi.y-a.y,v=b.y-poi.y;
	return (point){(u*b.x/v+a.x)/(1+u/v),poi.y};
}
int main ()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
		scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
		p[0]=a.y<b.y?a:b;
		p[1]=a.y>b.y?a:b;
		p[2]=c.y<d.y?c:d;
		p[3]=c.y>d.y?c:d;
		if(p[1].y>p[3].y)
		{
			swap(p[0],p[2]);
			swap(p[1],p[3]);
		}
		if(a.y==b.y || c.y==d.y)
		{
			printf("0.00\n");
			continue;
		}
		if(! intersect(a,b,c,d))
		{
			printf("0.00\n");
			continue;
		}
		if(par(a,b,c,d))
		{
			printf("0.00\n");
			continue;
		}
		e=intersection(a,b,c,d);
		//printf("%lf %lf\n%lf %lf\n%lf %lf\n",e.x,e.y,f.x,f.y,g.x,g.y);
		if((p[1].x>=e.x && p[3].x>=p[1].x && mult(e,p[1],p[3])>0.0) || 
		   (p[1].x<=e.x && p[1].x>=p[3].x && mult(e,p[3],p[1])>0.0))
		{
			printf("0.00\n");
			continue;
		}
		h=p[1];
		if(p[1].y==p[3].y) i=p[3];
		else i=opoint(p[1],p[2],p[3]);
		double ans=mult(e,h,i);
		if(ans<EPS)ans=-ans;
		printf("%.2f\n",ans/2.0+EPS);
	}
	
	return 0;
}