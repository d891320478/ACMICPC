#include <cstdio>
#include <cmath>
const double inf=1e-8;
int n;
struct point
{
	double x,y;
}a[200],o;
double r,dir;
bool flag;
double mul(point p0,point p1,point p2)
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
int main()
{
	while (scanf("%d",&n) && n>=3)
	{
		flag=0;
		scanf("%lf%lf%lf",&r,&o.x,&o.y);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		a[n+1]=a[1];
		for(int i=1;i<n;i++)
		{
			dir=mul(a[i],a[i+1],a[i+2]);
			if(fabs(dir)>inf)break;
		}
		for(int i=1;i<n;i++)
			if(mul(a[i],a[i+1],a[i+2])*dir<-inf)
			{
				printf("HOLE IS ILL-FORMED\n");
				flag=1;
				break;
			}
		if(flag)continue;
		for(int i=1;i<=n;i++)
			if(mul(o,a[i],a[i+1])*mul(o,a[i+1],a[i+2])<-inf)
			{
				printf("PEG WILL NOT FIT\n");
				flag=1;
				break;
			}
		if(flag)continue;
		
		for(int i=1;i<=n;i++)
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