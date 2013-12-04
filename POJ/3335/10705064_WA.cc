#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
#define N 1510
#define EPS 1e-8
struct point
{	double x,y;	}inp[N],p[N],q[N];
int n;	double r;	int cnt,curcnt;
double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point intersect(point u1,point u2,point v1,point v2)
{
	point ret=u1;
	double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			 ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x+=(u2.x-u1.x)*t;
	ret.y+=(u2.y-u1.y)*t;
	return ret;
}
inline void cut(point p1,point p2)
{
	int i;
	curcnt=0;
	for(i=1;i<=cnt;i++)
	{
		if(xmult(p[i],p2,p1)>EPS) q[++curcnt]=p[i];
		else
		{
			if(xmult(p[i-1],p2,p1)>EPS) q[++curcnt]=intersect(p[i],p[i-1],p1,p2);
			if(xmult(p[i+1],p2,p1)>EPS) q[++curcnt]=intersect(p[i],p[i+1],p1,p2);
		}
	}
	for(i=1;i<=curcnt;i++) p[i]=q[i];
	p[curcnt+1]=q[1];	p[0]=p[curcnt];	cnt=curcnt;
}
inline bool solve()//注意：默认点是顺时针，如果题目不是顺时针，规整化方向
{
	double a,b,c;
	for(int i=1;i<=n;i++) p[i]=inp[i];
	p[n+1]=p[1];	p[0]=p[n];	cnt=n;
	for(int i=1;i<=n;i++)
	{
		cut(inp[i],inp[i+1]);
		if(cnt==0)return 0;
	}
	return 1;
}
inline void gzh() //规整化方向，逆时针变顺时针，顺时针变逆时针
{
	for(int i=1;i<(n+1)/2;i++)	 swap(inp[i],inp[n-i]);
	inp[n+1]=inp[1];
}
double area(point *p,int n)//有向面积，顺时针为负，逆时针为正
{
	double s=0.0;
	for(int i=1;i<=n;i++)	s+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
	return s;
}
int main ()
{
	int tt,i;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)	scanf("%lf%lf",&inp[i].x,&inp[i].y);
		inp[n+1]=inp[1];
		if(area(inp,n)>0) gzh();
		if(solve())puts("YES");
		else puts("NO");
	}
	return 0;
}