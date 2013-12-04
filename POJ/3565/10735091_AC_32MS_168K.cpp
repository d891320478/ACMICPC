#include <cstdio>
#include <iostream>
using namespace std;
#define N 110
struct point
{
	double x,y;
}p[N],q[N];
int i,j,k,a[N],n;
double xmult(point p0, point p1, point p2)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool intersect(point u1,point u2, point v1,point v2)
{
	return (max(u1.x,u2.x)>=min(v1.x,v2.x)) && (max(v1.x,v2.x)>=min(u1.x,u2.x))
		&& (max(u1.y,u2.y)>=min(v1.y,v2.y)) && (max(v1.y,v2.y)>=min(u1.y,u2.y))
		&& (xmult(u1,v1,u2)*xmult(u1,u2,v2)>0) && (xmult(v1,u1,v2)*xmult(v1,v2,u2)>0);
}
int main ()
{
	while (scanf("%d",&n)!=-1)
	{
		for(i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i=1;i<=n;i++) scanf("%lf%lf",&q[i].x,&q[i].y);
		for(i=1;i<=n;i++) a[i]=i;
		for(i=1;i<=n;i++)
		{
			int flag=0;
			for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
			if(intersect(p[j],q[a[j]],p[k],q[a[k]]))
			{
				flag=1;
				swap(a[j],a[k]);
			}
			if(! flag)break;
		}
		for(i=1;i<=n;i++) printf("%d\n",a[i]);
	}
	
	return 0;
}