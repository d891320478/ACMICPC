#include <cstdio>
#include <cmath>
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define eps 1e-8
int n;
struct point
{
	double x,y;
}a[200],o;
double r,dir;
bool flag,tmp;
double mul(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dis(point u,point v)
{
	return (u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y);
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
point ptoline(point p,point l1,point l2)
{
	point t=p;
	t.x+=l1.y-l2.y,t.y+=l2.x-l1.x;
	return intersection(p,t,l1,l2);
}
bool is_convex(int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n && s[1]|s[2];i++)
		s[_sign(mul(p[(i+1)%n],p[(i+2)%n],p[i]))]=0;
	return s[1] | s[2];
}
bool inside_convex(point q,int n,point* p)
{
	int i,s[3]={1,1,1};
	for (i=0;i<n && s[1]|s[2] ;i++)
	s[_sign(mul(p[(i+1)%n],q,p[i]))]=0;
	return s[1] | s[2];
}
int main()
{
	while (scanf("%d",&n) && n>=3)
	{
		flag=0;
		scanf("%lf%lf%lf",&r,&o.x,&o.y);
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		a[n]=a[0];
		tmp=is_convex(n,a);
		if(! tmp)
		{
			printf("HOLE IS ILL-FORMED\n");
			continue;
		}
		tmp=inside_convex(o,n,a);
		if(! tmp)
		{
			printf("PEG WILL NOT FIT\n");
			continue;
		}
		for(int i=0;i<n;i++)
		{
			point ret=ptoline(o,a[i],a[i+1]);
			if(dis(ret,o)<r*r)
			{
				printf("PEG WILL NOT FIT\n");
				flag=1;
				break;
			}
		}
		if(! flag)printf("PEG WILL FIT\n");
	}
	
	return 0;
}